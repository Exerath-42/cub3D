/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:06:23 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/05 16:19:17 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_strafe(t_game *game, double c)
{
	int	grid_x;
	int	grid_y;

	game->player->pos_x -= c * (game->player->orientation_y * SPEED);
	grid_x = floor(game->player->pos_x);
	grid_y = floor(game->player->pos_y);
	if (game->data->map[grid_y][grid_x] == '1'
		|| game->data->map[grid_y][grid_x] == 'D')
		game->player->pos_x += c * (game->player->orientation_y * SPEED);
	game->player->pos_y += c * (game->player->orientation_x * SPEED);
	grid_x = floor(game->player->pos_x);
	grid_y = floor(game->player->pos_y);
	if (game->data->map[grid_y][grid_x] == '1'
		|| game->data->map[grid_y][grid_x] == 'D')
		game->player->pos_y -= c * (game->player->orientation_x * SPEED);
}

void	ft_move(t_game *game, double c)
{
	int	grid_x;
	int	grid_y;

	game->player->pos_x += c * (game->player->orientation_x * SPEED);
	grid_x = floor(game->player->pos_x);
	grid_y = floor(game->player->pos_y);
	if (game->data->map[grid_y][grid_x] == '1'
		|| game->data->map[grid_y][grid_x] == 'D')
		game->player->pos_x -= c * (game->player->orientation_x * SPEED);
	game->player->pos_y += c * (game->player->orientation_y * SPEED);
	grid_x = floor(game->player->pos_x);
	grid_y = floor(game->player->pos_y);
	if (game->data->map[grid_y][grid_x] == '1'
		|| game->data->map[grid_y][grid_x] == 'D')
		game->player->pos_y -= c * (game->player->orientation_y * SPEED);
}

void	ft_rotate(t_game *game, double c)
{
	game->player->orientation_x = game->player->orientation_x * cos(c * TURN)
		- game->player->orientation_y * sin(c * TURN);
	game->player->orientation_y = game->player->orientation_y * cos(c * TURN)
		+ game->player->orientation_x * sin(c * TURN);
}
