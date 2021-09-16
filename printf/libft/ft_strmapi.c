/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:16:47 by ldonita           #+#    #+#             */
/*   Updated: 2020/11/21 07:05:01 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	size_t	i;

	out = NULL;
	i = 0;
	if (s != NULL && f != NULL)
	{
		out = ft_strdup(s);
		if (out != NULL)
		{
			while (s[i] != '\0')
			{
				out[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (out);
}
