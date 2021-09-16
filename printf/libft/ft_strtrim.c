/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:17:07 by ldonita           #+#    #+#             */
/*   Updated: 2020/11/21 07:08:05 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in(char const c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	size_t	i;
	size_t	j;

	out = NULL;
	i = 0;
	j = 0;
	if (s1 != NULL && set != NULL)
	{
		j = ft_strlen(s1) - 1;
		while (is_in(s1[i], set) && s1[i] != '\0')
			i++;
		if (s1[i] != '\0')
			while (is_in(s1[j], set) && j != i)
				j--;
		out = ft_substr(s1, i, j - i + 1);
	}
	return (out);
}
