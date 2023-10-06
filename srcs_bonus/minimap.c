/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:32:02 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/05 16:21:43 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_draw_minimap(t_game *game, char **map, int posx, int posy)
{
	int		x;
	int		y;
	int		i;
	int		j;

	i = 0;
	y = ft_start(posy);
	while (y <= floor(posy) + 7 && map[y] != NULL)
	{
		j = -1;
		x = ft_start(posx);
		while (++j < 14 && map[y][x] != '\0' && x <= floor(posx) + 7)
		{
			if (map[y][x] == '1' || map[y][x] == 'D')
				ft_draw_tile(game, 1, j, i);
			else if (x == floor(posx) && y == floor(posy))
				ft_draw_tile(game, 2, j, i);
			else if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W' || map[y][x] == 'O')
				ft_draw_tile(game, 0, j, i);
			x++;
		}
		y++;
		i++;
	}
}

int	ft_start(int position)
{
	int	a;

	a = floor(position) - 7;
	if (a < 0)
		a = 0;
	return (a);
}

void	ft_draw_tile(t_game *game, int flag, int x, int y)
{
	int	color;
	int	i;
	int	j;

	if (flag == 1)
		color = WHITE;
	else if (flag == -1)
		color = GREY;
	else if (flag == 2)
		color = RED;
	else
		color = BLACK;
	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			ft_putpixel(game->image, (x * 10) + i, (y * 10) + j, color);
			i++;
		}
		j++;
	}
}
