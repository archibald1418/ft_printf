/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:14:19 by ldonita           #+#    #+#             */
/*   Updated: 2020/11/21 01:09:19 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		is_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static void			fill_digits(unsigned long n, char *str)
{
	if (n >= 10)
	{
		fill_digits(n / 10, str - 1);
		fill_digits(n % 10, str);
	}
	else
		*str = n + '0';
}

static size_t		count_digits(int n, size_t i)
{
	if (n == 0 && i == 0)
		return (1);
	if (n == 0)
		return (i);
	return (count_digits(n / 10, i + 1));
}

char				*ft_itoa(int n)
{
	char			*out;
	size_t			has_minus;
	size_t			ndigits;
	unsigned long	pos;

	pos = (unsigned long)n;
	ndigits = count_digits(n, 0);
	has_minus = is_neg(n);
	out = ft_calloc(has_minus + ndigits + 1, 1);
	if (out != NULL)
	{
		if (has_minus == 1)
		{
			pos = (unsigned long)n * (-1);
			out[0] = '-';
		}
		fill_digits(pos, has_minus + out + ndigits - 1);
	}
	return (out);
}
