/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:14:24 by ldonita           #+#    #+#             */
/*   Updated: 2020/11/21 01:19:22 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (dst != NULL || src != NULL)
	{
		while (n--)
		{
			*cdst = *csrc;
			if (*csrc == (unsigned char)c)
				return (cdst + 1);
			csrc++;
			cdst++;
		}
	}
	return (NULL);
}
