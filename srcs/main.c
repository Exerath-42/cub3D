/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:00:27 by lmurtin           #+#    #+#             */
/*   Updated: 2022/11/25 10:59:08 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_mapdata	*data;
	t_player	*player;

	data = parsing(argc, argv);
	player = malloc(sizeof(t_player));
	if (player == NULL)
		return (ft_clean_data(data), 1);
	ft_init_player(player, data);
	if (init_win(data, player) == NULL)
	{
		free(player);
		ft_clean_data(data);
		return (1);
	}
	return (0);
}
