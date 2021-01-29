/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:02:00 by ldonita           #+#    #+#             */
/*   Updated: 2021/01/29 19:02:01 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define IS_SPACE(c) ((c) == 32 || (9 <= (c) && (c) <= 13))

size_t			ft_strchri(char *fmt, int c, size_t i)
{
	while (fmt[i] != '\0')
	{
		if (fmt[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (i);
}

size_t	ft_alphchri(char *fmt, size_t i)
{
	while ((!ft_isalpha(fmt[i]) && fmt[i] != '%') && \
	(fmt[i] != '\0' && !IS_SPACE(fmt[i])))
		i++;
	return (i);
}

size_t			ft_ullen(unsigned long n, size_t i)
{
	if (n == 0 && i == 0)
		return (0); // width
	if (n == 0)
		return (i);
	return (ft_ullen(n / 10, i + 1));
}

unsigned long	ft_abs(long n)
{
	if (n < 0)
		return ((unsigned long)(n * (-1)));
	return ((unsigned long)n);
}