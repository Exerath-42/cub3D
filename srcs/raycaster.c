/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:35:45 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/06 14:25:20 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_raycaster(t_game *game)
{
	t_ray	ray;
	t_hit	hit;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.h = 0;
	hit.x = 0;
	hit.y = 0;
	hit.d = 0;
	game->ray = ray;
	game->hit = hit;
	ft_screen(game);
}

void	ft_screen(t_game *game)
{
	while (game->ray.i < WINDOW_W)
	{
		ft_ray(game);
		ft_dir(game);
		ft_ver(game, game->player);
		ft_hor(game, game->player);
		ft_column(game, ft_size(game), game->ray.i);
		game->ray.i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->image->img, 0, 0);
}

void	ft_ray(t_game *game)
{
	double	angle;
	double	dist;

	angle = ((double)game->ray.i - (WINDOW_W / 2)) * 33 / (WINDOW_W / 2);
	angle = angle * M_PI / 180;
	game->ray.x = game->player->orientation_x * cos(angle)
		- game->player->orientation_y * sin(angle);
	game->ray.y = game->player->orientation_y * cos(angle)
		+ game->player->orientation_x * sin(angle);
	dist = hypot(game->ray.x, game->ray.y);
	game->ray.x /= dist;
	game->ray.y /= dist;
}

void	ft_dir(t_game *game)
{
	if (game->ray.x >= 0)
		game->ray.h = 1;
	else
		game->ray.h = 0;
	if (game->ray.y >= 0)
		game->ray.v = 1;
	else
		game->ray.v = 0;
}
