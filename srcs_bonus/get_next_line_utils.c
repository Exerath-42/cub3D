/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:35:16 by lmurtin           #+#    #+#             */
/*   Updated: 2022/11/24 10:35:19 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../includes/get_next_line.h"

char	*ft_extract(t_reads *head, int count)
{
	t_reads	*node;
	char	*str;
	int		i;

	i = 0;
	node = head;
	if (count == 0)
		return (NULL);
	str = malloc(sizeof(char) * 20 * count + 1);
	if (str == NULL)
		return (NULL);
	while (node != NULL)
	{
		i = ft_process_node(&str, i, node);
		node = node->next;
	}
	str[i] = '\0';
	if (i == 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int	ft_process_node(char **str, int i, t_reads *node)
{
	int	j;
	int	k;

	j = -1;
	k = 0;
	while (++j < node->nb_read)
	{
		if (node->content[j] == '\n')
		{
			k++;
			if (k <= node->iter && node->count == 1)
				i = -1;
			else
			{
				str[0][i] = node->content[j];
				node->iter += 1;
				i++;
				break ;
			}
		}
		else
			str[0][i] = node->content[j];
		i++;
	}
	return (i);
}

void	ft_clean(t_reads *head, int count, int clear)
{
	t_reads	*node;
	t_reads	*tmp;

	node = head->next;
	if (node != NULL)
	{
		while (node->count != count)
		{
			tmp = node->next;
			free(node->content);
			free(node);
			node = tmp;
		}
		free(head->content);
		head->content = node->content;
		head->iter = node->iter;
		head->nb_read = node->nb_read;
		head->next = NULL;
		free(node);
	}
	if (clear == 1)
		free(head->content);
	return ;
}
