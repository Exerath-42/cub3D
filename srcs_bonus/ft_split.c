/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:31:20 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/05 16:20:51 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d_bonus.h"

static int	ft_tab_size(const char *str, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			size++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (size + 1);
}

static char	*ft_extract_str(const char *src, char c)
{
	char	*string;
	int		i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	string = malloc(sizeof(char) * (i + 1));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

static void	ft_free(char **tab, int index)
{
	while (index >= 0)
	{
		free(tab[index]);
		index--;
	}
}

static char	**ft_fill(char const *s, char **tab, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[i] = ft_extract_str(s, c);
			if (tab[i] == NULL)
			{
				ft_free(tab, i);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**tab;

	size = ft_tab_size(s, c);
	tab = malloc(sizeof(char *) * size);
	if (tab == NULL)
		return (NULL);
	tab = ft_fill(s, tab, c);
	return (tab);
}
