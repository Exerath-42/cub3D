/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:33:39 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/07 12:08:18 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_clean_images(t_game *game)
{
	if (game->image != NULL)
	{
		mlx_destroy_image(game->mlx, game->image->img);
		free(game->image);
	}
	if (game->tex_north != NULL && game->tex_north->img != NULL)
		mlx_destroy_image(game->mlx, game->tex_north->img);
	free(game->tex_north);
	if (game->tex_south != NULL && game->tex_south->img != NULL)
		mlx_destroy_image(game->mlx, game->tex_south->img);
	free(game->tex_south);
	if (game->tex_east != NULL && game->tex_east->img != NULL)
		mlx_destroy_image(game->mlx, game->tex_east->img);
	free(game->tex_east);
	if (game->tex_west != NULL && game->tex_west->img != NULL)
		mlx_destroy_image(game->mlx, game->tex_west->img);
	free(game->tex_west);
}

void	finish(int n)
{
	if (n == 0)
		write(1, "Work finished!\n", 16);
	if (n == 1)
		write(2, "Something went wrong.\n", 22);
	exit(n);
}

int	ft_clean_exit(t_game *game, int flag)
{
	if (game->mlx_win != NULL)
		mlx_destroy_window(game->mlx, game->mlx_win);
	ft_clean_images(game);
	ft_clean_bonus(game);
	if (game->mlx != NULL)
	{
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_clean_data(game->data);
	free(game->anim);
	free(game->player);
	free(game->key);
	free(game);
	if (flag == 1)
		finish(1);
	else
		finish(0);
	return (0);
}
