/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:02:57 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/05 16:19:17 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	ft_clean_bonus(t_game *game)
{
	if (game->doors->frame1 != NULL)
	{
		mlx_destroy_image(game->mlx, game->doors->frame1->img);
		free(game->doors->frame1);
	}
	if (game->doors->frame2 != NULL)
	{
		mlx_destroy_image(game->mlx, game->doors->frame2->img);
		free(game->doors->frame2);
	}
	if (game->doors->frame3 != NULL)
	{
		mlx_destroy_image(game->mlx, game->doors->frame3->img);
		free(game->doors->frame3);
	}
	if (game->doors->frame4 != NULL)
	{
		mlx_destroy_image(game->mlx, game->doors->frame4->img);
		free(game->doors->frame4);
	}
	ft_clean_bonus2(game);
}

void	ft_clean_bonus2(t_game *game)
{
	if (game->doors->frame5 != NULL)
	{
		mlx_destroy_image(game->mlx, game->doors->frame5->img);
		free(game->doors->frame5);
	}
	if (game->doors->frame6 != NULL)
	{
		mlx_destroy_image(game->mlx, game->doors->frame6->img);
		free(game->doors->frame6);
	}
	if (game->doors->frame7 != NULL)
	{
		mlx_destroy_image(game->mlx, game->doors->frame7->img);
		free(game->doors->frame7);
	}
	if (game->doors != NULL)
		free(game->doors);
}
