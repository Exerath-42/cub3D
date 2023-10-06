/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:02:22 by lmurtin           #+#    #+#             */
/*   Updated: 2022/11/25 10:49:58 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>
#include <fcntl.h>

/* scan file to extract informations and detect misconfigurations */
t_file	*ft_check_file(t_mapdata *data, char *filename)
{
	t_file	*node;
	char	**element;
	int		i;

	i = 0;
	data->file = ft_read_file(filename);
	if (data->file == NULL)
		return (NULL);
	node = data->file;
	while (node != NULL)
	{
		if (node->line[0] != '\n')
		{
			element = ft_split(node->line, ' ');
			if (element == NULL)
				return (ft_free_list(data->file), NULL);
			if (ft_analyse_elem(data, node, element, &i) == 1)
				return (NULL);
			ft_free_tab(element);
		}
		node = node->next;
	}
	return (data->file);
}

/* put each line of the file in a linked list */
/* no check at this point */
t_file	*ft_read_file(char *filename)
{
	char	*line;
	t_file	*file;
	t_file	*current;
	int		i;
	int		fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nUnable to read file.\n", 27), NULL);
	line = get_next_line(fd);
	file = NULL;
	while (line != NULL)
	{
		current = ft_lstnew(line);
		if (current == NULL)
			return (ft_free_list(file), NULL);
		current->index = i;
		current->len = ft_strlen(line);
		ft_lstadd(&file, current);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (file);
}

int	ft_analyse_elem(t_mapdata *data, t_file *node, char **element, int *i)
{
	int	check;

	check = check_id(element[0]);
	if (check == 1 || (check == 0 && *i < 6))
	{
		if (check == 0)
			write(2, "Error\nMap must be after other elements\n", 39);
		ft_free_tab(element);
		ft_free_list(data->file);
		return (1);
	}
	else if (check == 0)
		node->type = MAP;
	else if (check > 2)
	{
		if (check_texture(element, data, check) != 0)
		{
			ft_free_tab(element);
			ft_free_list(data->file);
			return (1);
		}
		(*i)++;
	}
	return (0);
}
