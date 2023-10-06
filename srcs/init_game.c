/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:06:13 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/06 19:15:44 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_hooks(t_game *game)
{
	game->key = malloc(sizeof(t_key));
	if (game->key == NULL)
		return (ft_clean_exit(game, 1), 1);
	game->key->w = 0;
	game->key->a = 0;
	game->key->s = 0;
	game->key->d = 0;
	game->key->left = 0;
	game->key->right = 0;
	game->loop = 0;
	return (0);
}

t_game	*ft_init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->image = NULL;
	game->data = NULL;
	game->player = NULL;
	game->tex_north = NULL;
	game->tex_south = NULL;
	game->tex_east = NULL;
	game->tex_west = NULL;
	game->key = NULL;
	return (game);
}

int	ft_init_tex(t_game *game, t_mapdata *data)
{
	game->tex_north = malloc(sizeof(t_image));
	if (game->tex_north == NULL)
		return (1);
	game->tex_north->img = mlx_xpm_file_to_image
		(game->mlx, data->north_texture, &game->tex_size_x, &game->tex_size_y);
	if (game->tex_north->img == NULL)
		return (write(2, "Error\nInvalid texture path\n", 27));
	game->tex_north->addr = mlx_get_data_addr(game->tex_north->img,
			&game->tex_north->bits_per_pixel, &game->tex_north->line_length,
			&game->tex_north->endian);
	game->tex_south = malloc(sizeof(t_image));
	if (game->tex_south == NULL)
		return (1);
	game->tex_south->img = mlx_xpm_file_to_image
		(game->mlx, data->south_texture, &game->tex_size_x, &game->tex_size_y);
	if (game->tex_south->img == NULL)
		return (write(2, "Error\nInvalid texture path\n", 27));
	game->tex_south->addr = mlx_get_data_addr(game->tex_south->img,
			&game->tex_south->bits_per_pixel, &game->tex_south->line_length,
			&game->tex_south->endian);
	return (ft_init_tex2(game, data));
}

int	ft_init_tex2(t_game *game, t_mapdata *data)
{
	game->tex_east = malloc(sizeof(t_image));
	if (game->tex_east == NULL)
		return (1);
	game->tex_east->img = mlx_xpm_file_to_image
		(game->mlx, data->east_texture, &game->tex_size_x, &game->tex_size_y);
	if (game->tex_east->img == NULL)
		return (write(2, "Error\nInvalid texture path\n", 27));
	game->tex_east->addr = mlx_get_data_addr(game->tex_east->img,
			&game->tex_east->bits_per_pixel, &game->tex_east->line_length,
			&game->tex_east->endian);
	game->tex_west = malloc(sizeof(t_image));
	if (game->tex_west == NULL)
		return (1);
	game->tex_west->img = mlx_xpm_file_to_image
		(game->mlx, data->west_texture, &game->tex_size_x, &game->tex_size_y);
	if (game->tex_west->img == NULL)
		return (write(2, "Error\nInvalid texture path\n", 27));
	game->tex_west->addr = mlx_get_data_addr(game->tex_west->img,
			&game->tex_west->bits_per_pixel, &game->tex_west->line_length,
			&game->tex_west->endian);
	return (0);
}
