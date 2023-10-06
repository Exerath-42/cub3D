/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmurtin <lmurtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:30:47 by lmurtin           #+#    #+#             */
/*   Updated: 2022/12/05 16:20:19 by lmurtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "cub3d_bonus.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static int	ft_isnum(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

static size_t	ft_strlenbr(const char *s)
{
	int	i;

	i = 0;
	while (ft_isnum(s[i]) == 1)
		i++;
	return (i);
}

static long	ft_atolong(const char *str, int neg)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = 0;
	if (ft_strlenbr(str) > 10)
	{
		if (neg > 0)
			return (-1);
		else
			return (0);
	}
	while (ft_isnum(str[i]) == 1)
	{
		tmp = tmp * 10 + str[i] - 48;
		i++;
	}
	return (tmp * neg);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == 45)
	{
		neg = -neg;
		i++;
	}
	else if (str[i] == 43)
		i++;
	if (ft_atolong(&str[i], neg) > INT_MAX)
		return (-1);
	else if (ft_atolong(&str[i], neg) < INT_MIN)
		return (-1);
	return ((int)ft_atolong(&str[i], neg));
}
