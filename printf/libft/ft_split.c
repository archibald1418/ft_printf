/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:15:22 by ldonita           #+#    #+#             */
/*   Updated: 2020/11/26 20:55:02 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		iter_chars(char const *s, char sep, size_t flag)
{
	size_t i;

	i = 0;
	while (((s[i] == sep) == flag) && (s[i] != '\0'))
		i++;
	return (i);
}

static size_t		count_words(char const *s, char c)
{
	size_t flag;
	size_t words;

	flag = 1;
	words = 0;
	while (*s != '\0')
	{
		s += iter_chars(s, c, flag);
		if (flag == 0)
			words++;
		flag = !flag;
	}
	return (words);
}

static char			**free_arr(char **arr, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ((char **)NULL);
}

static char			**fill_arr(char **arr, size_t len, char const *s, char sep)
{
	size_t leni;
	size_t flag;
	size_t i;

	i = 0;
	flag = 1;
	leni = 0;
	while (i < len && *s != '\0')
	{
		leni = iter_chars(s, sep, flag);
		if (flag == 0)
		{
			arr[i] = malloc((leni + 1) * sizeof(char)); 
			if (arr[i] == NULL)
				return (free_arr(arr, i));
			ft_strlcpy(arr[i], s, leni + 1);
			i++;
		}
		flag = !flag;
		s += leni;
	}
	arr[i] = NULL;
	return (arr);
}

char				**ft_split(char const *s, char c)
{
	size_t	nwords;
	char	**out;

	out = NULL;
	nwords = 0;
	if (s != NULL)
	{
		nwords = count_words(s, c);
		out = malloc((nwords + 1) * sizeof(char *));
		if (out != NULL)
			out = fill_arr(out, nwords, s, c);
	}
	return (out);
}
