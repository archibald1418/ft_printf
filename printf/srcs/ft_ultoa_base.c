/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:01:23 by ldonita           #+#    #+#             */
/*   Updated: 2021/01/29 19:02:10 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ALPHABET "0123456789abcdef"
#define IS_LOWER(c) (97 <= (c) && (c) <= 122)

static void			fill_digits(unsigned long n, char *str, int base, size_t caps) 
{
	if (n >= (unsigned long)base)
	{
		fill_digits(n / base, str - 1, base, caps);
		fill_digits(n % base, str, base, caps);
	}
	else
		*str = ALPHABET[n] - caps * IS_LOWER(ALPHABET[n]) * 32;
}

static size_t		count_digits(unsigned long n, size_t i, int base)
{
	if (n == 0 && i == 0)
		return (1);
	if (n == 0)
		return (i);
	return (count_digits(n / base, i + 1, base));
}

char				*ft_ultoa_base(unsigned long n, int base, size_t caps)
{

	size_t			ndigits;
	char			*out;

	ndigits = count_digits(n, 0, base);
	if (!(out = ft_calloc(21, sizeof(char))))
		return (NULL);
	fill_digits(n, out + ndigits - 1, base, caps);
	return (out);
}
