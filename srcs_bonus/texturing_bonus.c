/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:21:10 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/07 11:55:47 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <stdlib.h>
#include <math.h>

/* We need to find the impact column between ray and wall */
int	find_texture_col(t_game *game)
{
	double	impact_x;
	double	impact_y;
	int		coltex;

	impact_x = game->hit.x;
	impact_y = game->hit.y;
	coltex = 0;
	if (floor(game->hit.y) == game->hit.y)
	{
		if (game->ray.v == 1)
			coltex = (impact_x - floor(impact_x)) * game->tex_size_x;
		else if (game->ray.v == 0)
			coltex = (ceil(impact_x) - impact_x) * game->tex_size_x;
	}
	else if (floor(game->hit.x) == game->hit.x)
	{
		if (game->ray.h == 0)
			coltex = (impact_y - floor(impact_y)) * game->tex_size_y;
		else if (game->ray.h == 1)
			coltex = (ceil(impact_y) - impact_y) * game->tex_size_y;
	}
	return (coltex);
}

int	find_texel(t_game *game, int count_pix, int wall_heigh, int tex_x)
{
	double	exact_y;
	int		y;
	int		tex_color;

	exact_y = (count_pix * 128) / wall_heigh;
	y = floor(exact_y);
	if (game->hit.side == 'D')
		tex_color = ft_get_texel_color_bonus(game, tex_x, y);
	else
		tex_color = ft_get_texel_color(game, tex_x, y);
	return (tex_color);
}

int	ft_get_texel_color_bonus(t_game *game, int x, int y)
{
	int		texel;
	t_image	*texture;
	int		*tex_pixels;
	int		i;

	i = 0;
	while (i < game->nb_doors)
	{
		if ((game->anim[i].x == floor(game->hit.x)
				|| game->anim[i].x == floor(game->hit.x) - 1)
			&& (game->anim[i].y == floor(game->hit.y)
				|| game->anim[i].y == floor(game->hit.y) - 1))
			texture = game->anim[i].door;
		i++;
	}
	texel = y * texture->line_length + (texture->bits_per_pixel / 8) * x;
	tex_pixels = (int *)texture->addr;
	if (tex_pixels[texel / 4] == 1963783)
		return (ft_get_texel_color(game, x, y));
	else
		return (tex_pixels[texel / 4]);
}

int	ft_get_texel_color(t_game *game, int x, int y)
{
	int		texel;
	t_image	*texture;
	int		*tex_pixels;

	texture = NULL;
	if (floor(game->hit.y) == game->hit.y)
	{
		if (game->ray.v == 0)
			texture = game->tex_south;
		if (game->ray.v == 1)
			texture = game->tex_north;
	}
	else if (floor(game->hit.x) == game->hit.x)
	{
		if (game->ray.h == 1)
			texture = game->tex_west;
		if (game->ray.h == 0)
			texture = game->tex_east;
	}
	texel = y * texture->line_length + (texture->bits_per_pixel / 8) * x;
	tex_pixels = (int *)texture->addr;
	return (tex_pixels[texel / 4]);
}
