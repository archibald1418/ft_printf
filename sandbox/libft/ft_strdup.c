/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:15:42 by ldonita           #+#    #+#             */
/*   Updated: 2020/11/21 02:09:29 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	dstsize;

	dstsize = ft_strlen(s1) + 1;
	out = malloc(dstsize);
	if (out != NULL)
		ft_strlcpy(out, s1, dstsize);
	return (out);
}
