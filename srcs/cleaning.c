/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:02:57 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/06 14:27:55 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_list(t_file *lst)
{
	t_file	*tmp;
	t_file	*tmpnext;

	if (lst == NULL)
		return ;
	tmp = lst;
	while (tmp != NULL)
	{
		tmpnext = tmp->next;
		free(tmp->line);
		free(tmp);
		tmp = tmpnext;
	}
	lst = NULL;
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
	{
		return ;
	}
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_clean_data(t_mapdata *data)
{
	free(data->north_texture);
	free(data->south_texture);
	free(data->east_texture);
	free(data->west_texture);
	ft_free_tab(data->map);
	free(data);
}
