/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:02:07 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/05 16:19:17 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	**ft_get_map(t_file	*file)
{
	t_file	*node;
	t_file	*first;
	char	**map;
	int		len_max;

	node = file;
	first = NULL;
	len_max = 0;
	while (node != NULL)
	{
		if (node->type == MAP && first == NULL)
			first = node;
		if (first != NULL && len_max < node->len)
			len_max = node->len;
		node = node->next;
	}
	if (first == NULL)
	{
		write(2, "Error\nInvalid map content (no walls)\n", 37);
		return (NULL);
	}
	map = ft_extract_map(first, len_max);
	if (map == NULL)
		return (NULL);
	return (map);
}

char	**ft_extract_map(t_file *start, int len)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (ft_lstsize(start) + 1));
	if (map == NULL)
		return (NULL);
	map[ft_lstsize(start)] = NULL;
	while (start != NULL)
	{
		map[i] = ft_strdup_padding(start->line, len);
		if (map[i] == NULL)
			return (ft_free_tab(map), NULL);
		i++;
		start = start->next;
	}
	if (ft_check_map(map) != 0)
		return (ft_free_tab(map), NULL);
	return (map);
}

int	ft_check_map(char **map)
{
	int	x;
	int	y;
	int	player;

	y = 0;
	player = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (ft_check_tile(map, x, y, &player) != 0)
				return (1);
			x++;
		}
		y++;
	}
	if (player == 0)
		return (write(2, "Error\nNo player detected\n", 25));
	return (0);
}

int	ft_check_tile(char **map, int x, int y, int *player)
{
	if (map[y][x] == '0' || map[y][x] == 'D')
	{
		if (ft_surrounded(map, x, y) != 0)
			return (write(2, "Error\nMap not closed by walls\n", 30));
	}
	else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
			|| map[y][x] == 'W')
	{
		if (map[y][x - 1] == ' ' || map[y][x + 1] == ' '
			|| map[y - 1][x] == ' ' || map[y + 1][x] == ' ')
			return (write(2, "Error\nMap not closed by walls\n", 30));
		if (*player != 0)
			return (write(2, "Error\nMultiple players\n", 23));
		(*player)++;
	}
	else if (map[y][x] != '1' && map[y][x] != 'D' && map[y][x] != ' ')
		return (write(2, "Error\nInvalid character in map\n", 31));
	return (0);
}

/* checks if a '0' touches a space character */
int	ft_surrounded(char	**map, int x, int y)
{
	if (x == 0 || y == 0 || map[y][x + 1] == '\0' || map[y + 1] == NULL)
		return (1);
	if (map[y][x - 1] == ' ' || map[y][x + 1] == ' ' || map[y - 1][x] == ' '
			|| map[y + 1][x] == ' ')
		return (1);
	return (0);
}
