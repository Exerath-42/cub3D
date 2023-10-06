/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:57:51 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/06 14:49:09 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_tabsize(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

t_mapdata	*parsing(int argc, char **argv)
{
	t_mapdata	*data;

	if (ft_check_arg(argc, argv[1]) == 1)
	{
		write(2, "Error\nPlease give only one argument of .cub format.\n", 52);
		exit (1);
	}
	data = ft_get_data(argv[1]);
	if (data == NULL)
	{
		write(2, "Problem detected in the configuration file\n", 43);
		exit (2);
	}
	data->rowsize = ft_strlen(data->map[0]);
	data->colsize = ft_tabsize(data->map);
	printf("File OK, Map OK\n");
	return (data);
}

int	ft_check_arg(int argc, char *arg)
{
	int	len;
	int	fd;

	if (argc != 2 || arg == NULL)
		return (1);
	len = 0;
	while (arg[len] != '\0')
		len++;
	if (arg[len - 1] != 'b' || arg[len - 2] != 'u'
		|| arg[len - 3] != 'c' || arg[len - 4] != '.')
		return (1);
	fd = open(arg, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

t_mapdata	*ft_get_data(char *filename)
{
	t_mapdata	*data;
	t_file		*file;

	data = malloc(sizeof(t_mapdata));
	if (data == NULL)
		return (NULL);
	ft_init_data(data);
	file = ft_check_file(data, filename);
	if (file == NULL)
	{
		ft_clean_data(data);
		return (NULL);
	}
	data->map = ft_get_map(file);
	if (data->map == NULL)
	{
		ft_clean_data(data);
		ft_free_list(file);
		return (NULL);
	}
	ft_free_list(file);
	return (data);
}

void	ft_init_data(t_mapdata *data)
{
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->east_texture = NULL;
	data->west_texture = NULL;
	data->floor_color = -1;
	data->ceiling_color = -1;
	data->map = NULL;
	return ;
}
