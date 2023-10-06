/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:45:17 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/07 11:43:33 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_check_door(t_game *game, int precise_x, int precise_y, int flag)
{
	int	x;
	int	y;

	x = (int)floor(precise_x);
	y = (int)floor(precise_y);
	if (flag == 0)
	{
		if (game->data->map[y][(int)(precise_x - 1 + game->ray.h)] == 'D'
			|| game->data->map[y][(int)(precise_x - 1 + game->ray.h)] == 'O')
			return (1);
	}
	else if (flag == 1)
	{
		if (game->data->map[(int)(precise_y - 1 + game->ray.v)][x] == 'D'
			|| game->data->map[(int)(precise_y - 1 + game->ray.v)][x] == 'O')
			return (1);
	}
	return (0);
}

static void	set_values(t_game *game, int flag, double x, double y)
{
	if (flag == 0)
	{
		game->hit.x = x;
		game->hit.y = y;
		game->hit.d = 1000000000;
	}
	else if (flag == 1)
	{
		game->hit.x = x;
		game->hit.y = y;
		game->hit.d = hypot(x - game->player->pos_x, y - game->player->pos_y);
	}
	else
		return ;
}

void	ft_ver(t_game *game, t_player *player)
{
	double	x;
	double	y;

	x = floor(player->pos_x) + game->ray.h;
	y = player->pos_y + (x - player->pos_x) * (game->ray.y / game->ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < game->data->colsize
		&& (game->data->map[(int)floor(y)][(int)(x - 1 + game->ray.h)] != ' '))
	{
		if (game->data->map[(int)floor(y)][(int)(x - 1 + game->ray.h)] == '1'
			|| ft_check_door(game, x, y, 0) == 1)
		{
			if (game->data->map[(int)y][(int)(x - 1 + game->ray.h)] != '1')
				game->hit.side = 'D';
			else
				game->hit.side = 'N';
			set_values(game, 1, x, y);
			return ;
		}
		x += (2 * game->ray.h - 1);
		y += (2 * game->ray.h - 1) * game->ray.y / game->ray.x;
	}
	set_values(game, 0, player->pos_x, player->pos_y);
}

void	ft_hor(t_game *game, t_player *player)
{
	double	y;
	double	x;

	y = floor(player->pos_y) + game->ray.v;
	x = player->pos_x + (y - player->pos_y) * (game->ray.x / game->ray.y);
	while ((int)floor(x) > 0 && (int)floor(x) < game->data->rowsize
		&& (game->data->map[(int)(y - 1 + game->ray.v)][(int)floor(x)] != ' '))
	{
		if (game->data->map[(int)(y - 1 + game->ray.v)][(int)floor(x)] == '1'
			|| ft_check_door(game, x, y, 1) == 1)
		{
			if (game->hit.d > hypot(x - player->pos_x, y - player->pos_y))
			{
				if (game->data->map[(int)(y - 1 + game->ray.v)][(int)x] != '1')
					game->hit.side = 'D';
				else
					game->hit.side = 'W';
				set_values(game, 1, x, y);
			}
			return ;
		}
		y += (2 * game->ray.v - 1);
		x += (2 * game->ray.v - 1) * game->ray.x / game->ray.y;
	}
}

void	ft_column(t_game *game, int size, int screen_x)
{
	int				color;
	int				start;
	int				count;
	int				coltex;

	start = WINDOW_W * (WINDOW_H - size) / 2;
	if (size > WINDOW_H)
		count = (size - WINDOW_H) / 2;
	else
		count = 0;
	color = game->data->ceiling_color;
	coltex = find_texture_col(game);
	while (game->ray.i < WINDOW_W * WINDOW_H)
	{
		if (game->ray.i >= start && count < size)
		{
			color = find_texel(game, count, size, coltex);
			count++;
		}
		else if (count == size)
			color = game->data->floor_color;
		ft_putpixel(game->image, screen_x, game->ray.i / WINDOW_W, color);
		game->ray.i += WINDOW_W;
	}
	game->ray.i -= WINDOW_W * WINDOW_H;
}
