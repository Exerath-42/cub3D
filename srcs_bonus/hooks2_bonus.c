/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:54:31 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/07 11:52:00 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	anim_door2(t_game *game, int x, int y, int flag)
{
	int	i;

	i = 0;
	while (i < game->nb_doors)
	{
		if (game->anim[i].x == x && game->anim[i].y == y)
		{
			game->anim[i].anim = flag;
			game->ongoing = 1 * flag;
		}
		i++;
	}
	return ;
}

int	ft_anim_door(t_game *game)
{
	int	x;
	int	y;

	x = (int)game->player->pos_x;
	y = (int)game->player->pos_y;
	if (game->ongoing != 0)
		return (0);
	if (game->data->map[y][x - 1] == 'D')
		anim_door2(game, x - 1, y, 1);
	if (game->data->map[y][x + 1] == 'D')
		anim_door2(game, x + 1, y, 1);
	if (game->data->map[y - 1][x] == 'D')
		anim_door2(game, x, y - 1, 1);
	if (game->data->map[y + 1][x] == 'D')
		anim_door2(game, x, y + 1, 1);
	if (game->data->map[y][x - 1] == 'O')
		anim_door2(game, x - 1, y, -1);
	if (game->data->map[y][x + 1] == 'O')
		anim_door2(game, x + 1, y, -1);
	if (game->data->map[y - 1][x] == 'O')
		anim_door2(game, x, y - 1, -1);
	if (game->data->map[y + 1][x] == 'O')
		anim_door2(game, x, y + 1, -1);
	return (0);
}

int	ft_change_door_status(t_game *game, int i, int flag)
{
	game->data->map[game->anim[i].y][game->anim[i].x] += 11 * flag;
	return (0);
}
