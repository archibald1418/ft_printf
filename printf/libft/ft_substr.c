/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:17:11 by ldonita           #+#    #+#             */
/*   Updated: 2020/11/21 02:44:00 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	dstsize;

	dstsize = len + 1;
	out = malloc(dstsize);
	if (out != NULL)
	{
		if (s == NULL || *s == '\0' || start >= ft_strlen(s))
			out[0] = '\0';
		else
			ft_strlcpy(out, s + start, dstsize);
	}
	return (out);
}
