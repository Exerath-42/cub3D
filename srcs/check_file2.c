/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:04:42 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/06 19:18:44 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>
#include <fcntl.h>

int	check_id(char *first)
{
	if (first[0] == '1' || first[0] == '0' || first[0] == '\n')
		return (0);
	if (ft_strncmp(first, "NO", 3) == 0)
		return (NORTH);
	if (ft_strncmp(first, "SO", 3) == 0)
		return (SOUTH);
	if (ft_strncmp(first, "EA", 3) == 0)
		return (EAST);
	if (ft_strncmp(first, "WE", 3) == 0)
		return (WEST);
	if (ft_strncmp(first, "F", 2) == 0)
		return (FLOOR);
	if (ft_strncmp(first, "C", 2) == 0)
		return (CEILING);
	write(2, "Error\nInvalid characters in file\n", 33);
	return (1);
}

int	check_texture(char **element, t_mapdata *data, int flag)
{
	if (element[2] != NULL)
		return (write(2, "Error\nToo many info in element\n", 31));
	if (flag == NORTH)
	{
		if (data->north_texture != NULL)
			return (write(2, "Error\nDuplicated texture informations\n", 38));
		data->north_texture = ft_strdup(element[1]);
		return (0);
	}
	if (flag == SOUTH)
	{
		if (data->south_texture != NULL)
			return (write(2, "Error\nDuplicated texture informations\n", 38));
		data->south_texture = ft_strdup(element[1]);
		return (0);
	}
	return (check_texture_2(element, data, flag));
}

int	check_texture_2(char **element, t_mapdata *data, int flag)
{
	if (flag == EAST)
	{
		if (data->east_texture != NULL)
			return (write(2, "Error\nDuplicated texture informations\n", 38));
		data->east_texture = ft_strdup(element[1]);
		return (0);
	}
	if (flag == WEST)
	{
		if (data->west_texture != NULL)
			return (write(2, "Error\nDuplicated texture informations\n", 38));
		data->west_texture = ft_strdup(element[1]);
		return (0);
	}
	return (check_id_colors(element, data, flag));
}
