/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:33:14 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/07 12:06:25 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	game->anim = ft_find_doors(game, data->map);
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

t_door	*ft_find_doors(t_game *game, char **map)
{
	int		x;
	int		y;
	int		nb;
	t_door	*tab;

	y = 0;
	nb = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != ' ' && map[y][x] != '\n' && map[y][x] != '\0')
		{
			if (map[y][x] == 'D')
				nb++;
			x++;
		}
		y++;
	}
	tab = malloc(sizeof(t_door) * nb);
	if (tab == NULL)
		return (NULL);
	game->nb_doors = nb;
	ft_track_doors(map, tab);
	return (tab);
}

void	ft_track_doors(char **map, t_door *tab)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != ' ' && map[y][x] != '\n' && map[y][x] != '\0')
		{
			if (map[y][x] == 'D')
			{
				tab[i].x = x;
				tab[i].y = y;
				tab[i].anim = 0;
				i++;
			}
			x++;
		}
		y++;
	}
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
