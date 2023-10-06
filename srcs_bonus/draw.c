/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:31:43 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/05 16:20:03 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	floor_ceiling_draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_H / 2 + 1)
	{
		x = 0;
		while (x < WINDOW_W)
		{
			ft_putpixel(game->image, x, y, game->data->ceiling_color);
			x++;
		}
		y++;
	}
	while (y < WINDOW_H)
	{
		x = 0;
		while (x < WINDOW_W)
		{
			ft_putpixel(game->image, x, y, game->data->floor_color);
			x++;
		}
		y++;
	}
}
