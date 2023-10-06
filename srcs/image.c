/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:33:14 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/06 19:17:20 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_game	*init_win(t_mapdata *data, t_player *player)
{
	t_game		*game;

	game = ft_init_game();
	if (game == NULL)
		return (NULL);
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (free(game), NULL);
	game->data = data;
	game->player = player;
	if (ft_init_tex(game, data) != 0)
		return (ft_clean_exit(game, 1), NULL);
	game->mlx_win = mlx_new_window(game->mlx, WINDOW_W, WINDOW_H, "cub3d");
	if (game->mlx_win == NULL)
		return (ft_clean_exit(game, 1), NULL);
	ft_init_hooks(game);
	game->image = init_image(game->mlx, game);
	ft_raycaster(game);
	hooks(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->image->img, 0, 0);
	mlx_loop(game->mlx);
	return (game);
}

t_image	*init_image(void *mlx, t_game *game)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (img == NULL)
		ft_clean_exit(game, 1);
	img->img = mlx_new_image(mlx, WINDOW_W, WINDOW_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
								&img->line_length, &img->endian);
	if (img->addr == NULL)
		ft_clean_exit(game, 1);
	return (img);
}

void	ft_putpixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
