/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:15:45 by ldonita           #+#    #+#             */
/*   Updated: 2020/11/21 02:50:11 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	dstsize;
	size_t	s1len;
	size_t	s2len;

	out = NULL;
	dstsize = 0;
	s1len = 0;
	s2len = 0;
	if (s1 != NULL && s2 != NULL)
	{
		s1len = ft_strlen(s1);
		s2len = ft_strlen(s2);
		dstsize = s1len + s2len + 1;
		out = ft_calloc(dstsize, 1);
		if (out != NULL)
		{
			ft_memcpy(out, s1, s1len);
			ft_memcpy(out + s1len, s2, s2len);
		}
	}
	return (out);
}
