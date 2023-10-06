/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:45:17 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/06 14:27:30 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ver(t_game *game, t_player *player)
{
	double	x;
	double	y;

	x = floor(player->pos_x) + game->ray.h;
	y = player->pos_y + (x - player->pos_x) * (game->ray.y / game->ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < game->data->colsize)
	{
		if (game->data->map[(int)floor(y)][(int)(x - 1 + game->ray.h)] == ' ')
			break ;
		if (game->data->map[(int)floor(y)][(int)(x - 1 + game->ray.h)] == '1')
		{
			game->hit.side = 'W';
			game->hit.x = x;
			game->hit.y = y;
			game->hit.d = hypot(x - player->pos_x, y - player->pos_y);
			return ;
		}
		x += (2 * game->ray.h - 1);
		y += (2 * game->ray.h - 1) * game->ray.y / game->ray.x;
	}
	game->hit.x = player->pos_x;
	game->hit.y = player->pos_y;
	game->hit.d = 1000000000;
}

void	ft_hor(t_game *game, t_player *player)
{
	double	y;
	double	x;

	y = floor(player->pos_y) + game->ray.v;
	x = player->pos_x + (y - player->pos_y) * (game->ray.x / game->ray.y);
	while ((int)floor(x) > 0 && (int)floor(x) < game->data->rowsize)
	{
		if (game->data->map[(int)(y - 1 + game->ray.v)][(int)floor(x)] == ' ')
			break ;
		if (game->data->map[(int)(y - 1 + game->ray.v)][(int)floor(x)] == '1')
		{
			if (game->hit.d > hypot(x - player->pos_x, y - player->pos_y))
			{
				game->hit.side = 'N';
				game->hit.x = x;
				game->hit.y = y;
				game->hit.d = hypot(x - player->pos_x, y - player->pos_y);
			}
			return ;
		}
		y += (2 * game->ray.v - 1);
		x += (2 * game->ray.v - 1) * game->ray.x / game->ray.y;
	}
}

int	ft_size(t_game *game)
{
	double	correc;
	double	fisheye;

	fisheye = fabs((double)game->ray.i / (WINDOW_W / 2) - 1);
	fisheye *= 28 * M_PI / 180;
	correc = (double)game->hit.d * cos(fisheye);
	return (round(WINDOW_H / correc));
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
