/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:32:25 by lmurtin           #+#    #+#             */
/*   Updated: 2022/11/24 10:32:28 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	player_found(t_player *player, t_mapdata *data, int x, int y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	if (data->map[y][x] == 'N')
		player->orientation_y = -1;
	else if (data->map[y][x] == 'S')
		player->orientation_y = 1;
	else if (data->map[y][x] == 'E')
		player->orientation_x = 1;
	else if (data->map[y][x] == 'W')
		player->orientation_x = -1;
}

void	ft_init_player(t_player *player, t_mapdata *data)
{
	int			x;
	int			y;

	y = 0;
	player->orientation_x = 0;
	player->orientation_y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				player_found(player, data, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}
