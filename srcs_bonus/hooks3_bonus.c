/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:13:26 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/07 12:13:28 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_open(t_game *game)
{
	int	i;

	i = 0;
	if (game->loop % 10 == 0)
	{
		while (i < game->nb_doors)
		{
			ft_open_door(game, i);
			i++;
		}
	}
	game->loop++;
	if (game->loop == 100000)
		game->loop = 0;
}

void	ft_close(t_game *game)
{
	int	i;

	i = 0;
	if (game->loop % 10 == 0)
	{
		while (i < game->nb_doors)
		{
			ft_close_door(game, i);
			i++;
		}
	}
	game->loop++;
	if (game->loop == 100000)
		game->loop = 0;
}

void	ft_open_door(t_game *game, int i)
{
	if (game->anim[i].anim == 0)
		return ;
	game->ongoing = 1;
	if (game->anim[i].anim == 1)
		game->anim[i].door = game->doors->frame1;
	else if (game->anim[i].anim == 2)
		game->anim[i].door = game->doors->frame2;
	else if (game->anim[i].anim == 3)
		game->anim[i].door = game->doors->frame3;
	else if (game->anim[i].anim == 4)
		game->anim[i].door = game->doors->frame4;
	else if (game->anim[i].anim == 5)
		game->anim[i].door = game->doors->frame5;
	else if (game->anim[i].anim == 6)
		game->anim[i].door = game->doors->frame6;
	else if (game->anim[i].anim == 7)
	{
		game->anim[i].door = game->doors->frame7;
		game->anim[i].anim = -1;
		ft_change_door_status(game, i, 1);
		game->ongoing = 0;
	}
	game->anim[i].anim++;
}

void	ft_close_door(t_game *game, int i)
{
	if (game->anim[i].anim == 0)
		return ;
	game->ongoing = -1;
	if (game->anim[i].anim == -1)
		game->anim[i].door = game->doors->frame7;
	else if (game->anim[i].anim == -2)
		game->anim[i].door = game->doors->frame6;
	else if (game->anim[i].anim == -3)
		game->anim[i].door = game->doors->frame5;
	else if (game->anim[i].anim == -4)
		game->anim[i].door = game->doors->frame4;
	else if (game->anim[i].anim == -5)
		game->anim[i].door = game->doors->frame3;
	else if (game->anim[i].anim == -6)
		game->anim[i].door = game->doors->frame2;
	else if (game->anim[i].anim == -7)
	{
		game->anim[i].door = game->doors->frame1;
		game->anim[i].anim = 1;
		ft_change_door_status(game, i, -1);
		game->ongoing = 0;
	}
	game->anim[i].anim--;
}
