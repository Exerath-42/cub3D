/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:01:53 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/07 11:43:25 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_init_bonus2(t_game *game);
int	ft_init_bonus3(t_game *game);
int	ft_init_bonus4(t_game *game);

int	ft_init_bonus(t_game *game)
{
	int	i;

	i = -1;
	game->doors = malloc(sizeof(t_sprite));
	if (game->doors == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame1 = malloc(sizeof(t_image));
	if (game->doors->frame1 == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame1->img = mlx_xpm_file_to_image
		(game->mlx, "./textures/door1.xpm",
			&game->doors->size_x, &game->doors->size_y);
	if (game->doors->frame1->img == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame1->addr = mlx_get_data_addr(game->doors->frame1->img,
			&game->doors->frame1->bits_per_pixel,
			&game->doors->frame1->line_length, &game->doors->frame1->endian);
	ft_init_bonus2(game);
	while (++i < game->nb_doors)
		game->anim[i].door = game->doors->frame1;
	game->ongoing = 0;
	return (0);
}

int	ft_init_bonus2(t_game *game)
{
	game->doors->frame2 = malloc(sizeof(t_image));
	if (game->doors->frame2 == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame2->img = mlx_xpm_file_to_image
		(game->mlx, "./textures/door2.xpm",
			&game->doors->size_x, &game->doors->size_y);
	if (game->doors->frame2->img == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame2->addr = mlx_get_data_addr(game->doors->frame2->img,
			&game->doors->frame2->bits_per_pixel,
			&game->doors->frame2->line_length, &game->doors->frame2->endian);
	game->doors->frame3 = malloc(sizeof(t_image));
	if (game->doors->frame3 == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame3->img = mlx_xpm_file_to_image
		(game->mlx, "./textures/door3.xpm",
			&game->doors->size_x, &game->doors->size_y);
	if (game->doors->frame3->img == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame3->addr = mlx_get_data_addr(game->doors->frame3->img,
			&game->doors->frame3->bits_per_pixel,
			&game->doors->frame3->line_length, &game->doors->frame3->endian);
	ft_init_bonus3(game);
	return (0);
}

int	ft_init_bonus3(t_game *game)
{
	game->doors->frame4 = malloc(sizeof(t_image));
	if (game->doors->frame4 == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame4->img = mlx_xpm_file_to_image
		(game->mlx, "./textures/door4.xpm",
			&game->doors->size_x, &game->doors->size_y);
	if (game->doors->frame4->img == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame4->addr = mlx_get_data_addr(game->doors->frame4->img,
			&game->doors->frame4->bits_per_pixel,
			&game->doors->frame4->line_length, &game->doors->frame4->endian);
	game->doors->frame5 = malloc(sizeof(t_image));
	if (game->doors->frame5 == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame5->img = mlx_xpm_file_to_image
		(game->mlx, "./textures/door5.xpm",
			&game->doors->size_x, &game->doors->size_y);
	if (game->doors->frame5->img == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame5->addr = mlx_get_data_addr(game->doors->frame5->img,
			&game->doors->frame5->bits_per_pixel,
			&game->doors->frame5->line_length, &game->doors->frame5->endian);
	ft_init_bonus4(game);
	return (0);
}

int	ft_init_bonus4(t_game *game)
{
	game->doors->frame6 = malloc(sizeof(t_image));
	if (game->doors->frame6 == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame6->img = mlx_xpm_file_to_image
		(game->mlx, "./textures/door6.xpm",
			&game->doors->size_x, &game->doors->size_y);
	if (game->doors->frame6->img == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame6->addr = mlx_get_data_addr(game->doors->frame6->img,
			&game->doors->frame6->bits_per_pixel,
			&game->doors->frame6->line_length, &game->doors->frame6->endian);
	game->doors->frame7 = malloc(sizeof(t_image));
	if (game->doors->frame7 == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame7->img = mlx_xpm_file_to_image
		(game->mlx, "./textures/door7.xpm",
			&game->doors->size_x, &game->doors->size_y);
	if (game->doors->frame7->img == NULL)
		ft_clean_exit(game, 1);
	game->doors->frame7->addr = mlx_get_data_addr(game->doors->frame7->img,
			&game->doors->frame7->bits_per_pixel,
			&game->doors->frame7->line_length, &game->doors->frame7->endian);
	return (0);
}
