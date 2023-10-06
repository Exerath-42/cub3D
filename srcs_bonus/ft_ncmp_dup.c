/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncmp_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:31:02 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/05 16:20:38 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d_bonus.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				j;
	unsigned char	*u1;
	unsigned char	*u2;

	i = 0;
	j = 0;
	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (i < n)
	{
		if ((u1[i] == '\0') || (u2[i] == '\0'))
		{
			j = u1[i] - u2[i];
			break ;
		}
		else if (u1[i] != u2[i])
		{
			j = u1[i] - u2[i];
			break ;
		}
		else if (u1[i] == u2[i])
			i++;
	}
	return (j);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (tab == NULL)
		return (0);
	while (src[i] != '\n')
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strdup_padding(const char *src, int len)
{
	char	*tab;
	int		i;

	i = 0;
	if (src[0] == '\n')
		return (write(2, "Error\nEmpty line within map content\n", 36), NULL);
	tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (NULL);
	while (src[i] != '\n' && src[i] != '\0')
	{
		tab[i] = src[i];
		i++;
	}
	while (i < len)
	{
		tab[i] = ' ';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
