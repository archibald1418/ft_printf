/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:13:21 by ldonita           #+#    #+#             */
/*   Updated: 2020/11/26 14:52:03 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*iter_spaces(char *c)
{
	while (*c != '\0' && ((*c == 32) || (9 <= *c && *c <= 13)))
	{
		c++;
	}
	return (c);
}

static int		is_int(long num)
{
	return (INT_MIN <= num && num <= INT_MAX);
}

static long		iter_digits(const char *str, int sign)
{
	long num;

	num = 0;
	str += (sign != 0);
	while (ft_isdigit((int)*str) && is_int(num))
	{
		num = num * 10 + ((int)*str - 48);
		str++;
	}
	if (sign < 0)
		return (num * -1);
	return (num);
}

static int		get_sign(const char *str)
{
	if (*(unsigned char *)str == '+')
		return (1);
	if (*(unsigned char *)str == '-')
		return (-1);
	return (0);
}

int				ft_atoi(const char *str)
{
	long num;
	char *cstr;

	cstr = iter_spaces((char *)str);
	num = iter_digits(cstr, get_sign(cstr));
	if (num < INT_MIN)
		return (-1);
	if (num > INT_MAX)
		return (1);
	return ((int)num); 
}
