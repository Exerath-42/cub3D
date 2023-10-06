/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:02:40 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/05 16:19:17 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_id_colors(char **element, t_mapdata *data, int flag)
{
	int	rgb;

	if (element[0][1] != '\0' || (element[0][0] != 'F' && element[0][0] != 'C'))
		return (1);
	rgb = ft_getcolor(element[1]);
	if (rgb == -1)
	{
		write(2, "Error\nMisconfiguration in RGB values\n", 37);
		return (1);
	}
	if (flag == FLOOR)
	{
		if (data->floor_color != -1)
			return (write(2, "Error\nDuplicated color informations\n", 36));
		data->floor_color = rgb;
		return (0);
	}
	if (flag == CEILING)
	{
		if (data->ceiling_color != -1)
			return (write(2, "Error\nDuplicated color informations\n", 36));
		data->ceiling_color = rgb;
		return (0);
	}
	return (2);
}

int	ft_getcolor(char *info)
{
	char	**rgb_str;
	int		rgb[3];
	int		i;
	int		value;

	i = 0;
	rgb_str = ft_split(info, ',');
	if (rgb_str == NULL)
		return (-1);
	while (rgb_str[i] != NULL && rgb_str[i][0] != '\n')
		i++;
	if (i != 3)
		return (ft_free_tab(rgb_str), -1);
	i = 0;
	while (i < 3)
	{
		value = ft_atoi(rgb_str[i]);
		if (value < 0 || value > 255)
			return (ft_free_tab(rgb_str), -1);
		rgb[i] = value;
		i++;
	}
	ft_free_tab(rgb_str);
	return (ft_rgb_to_int(rgb[0], rgb[1], rgb[2]));
}

int	ft_rgb_to_int(int red, int green, int blue)
{
	int	color;
	int	transp;

	transp = 0;
	color = (transp << 24 | red << 16 | green << 8 | blue);
	return (color);
}
