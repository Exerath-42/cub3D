/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:35:28 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/06 14:41:59 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, key_release, game);
	mlx_hook(game->mlx_win, 17, 0, closer, game);
	mlx_loop_hook(game->mlx, refresh, game);
}

int	closer(t_game *game)
{
	ft_clean_exit(game, 0);
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == ESCAPE)
		closer(game);
	else if (key == KEY_W)
		game->key->w = 1;
	else if (key == KEY_A)
		game->key->a = 1;
	else if (key == KEY_S)
		game->key->s = 1;
	else if (key == KEY_D)
		game->key->d = 1;
	else if (key == KEY_LEFT)
		game->key->left = 1;
	else if (key == KEY_RIGHT)
		game->key->right = 1;
	return (key);
}

int	key_release(int key, t_game *game)
{
	if (key == KEY_W)
		game->key->w = 0;
	else if (key == KEY_A)
		game->key->a = 0;
	else if (key == KEY_S)
		game->key->s = 0;
	else if (key == KEY_D)
		game->key->d = 0;
	else if (key == KEY_LEFT)
		game->key->left = 0;
	else if (key == KEY_RIGHT)
		game->key->right = 0;
	return (key);
}

int	refresh(t_game *game)
{
	if (game->key->w == 1)
		ft_move(game, 1);
	if (game->key->a == 1)
		ft_strafe(game, -1);
	if (game->key->s == 1)
		ft_move(game, -1);
	if (game->key->d == 1)
		ft_strafe(game, 1);
	if (game->key->left == 1)
		ft_rotate(game, -1);
	if (game->key->right == 1)
		ft_rotate(game, 1);
	ft_raycaster(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->image->img, 0, 0);
	game->loop++;
	if (game->loop == 100000)
		game->loop = 0;
	return (0);
}
