/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:01:41 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/05 16:19:17 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_lstadd(t_file **alst, t_file *new)
{
	t_file	*last;

	last = ft_lstlast_mod(*alst);
	if (last == NULL)
	{
		*alst = new;
		new->prev = NULL;
	}
	else
	{
		last->next = new;
		new->prev = last;
	}
	new->next = NULL;
}

t_file	*ft_lstnew(char *line)
{
	t_file	*new;

	new = malloc(sizeof(t_file));
	if (new == NULL)
		return (NULL);
	new->line = line;
	new->type = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_file	*ft_lstlast_mod(t_file *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_file *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		else
			i++;
	}
	if (c == '\0')
		return (0);
	else
		return (-1);
}
