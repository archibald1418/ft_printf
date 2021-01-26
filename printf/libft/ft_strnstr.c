/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:16:55 by ldonita           #+#    #+#             */
/*   Updated: 2020/11/21 02:25:30 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t needlen;

	i = 0;
	needlen = 0;
	if ((haystack == NULL || needle == NULL) || *needle == '\0')
		return ((char *)haystack);
	needlen = ft_strlen(needle);
	if (len > 0)
	{
		while (((i + needlen - 1) < len) && *(haystack + needlen - 1) != '\0')
		{
			if (ft_strncmp(haystack, needle, needlen) == 0)
				return ((char *)haystack);
			haystack++;
			i++;
		}
	}
	return (NULL);
}
