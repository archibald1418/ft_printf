/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 05:22:10 by ldonita           #+#    #+#             */
/*   Updated: 2021/01/20 17:24:02 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		while (i++ < len)
			*cdst++ = *csrc++;
	else if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			*(cdst + i - 1) = *(csrc + i - 1);
			i--;
		}
	}
	return (dst);
}

ssize_t		ft_memchri(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;

	i = 0;
	cs = (unsigned char *)s;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

void		*ft_memdup(const void *s, size_t size)
{
	void *out;

	if (!(out = malloc(size + 1)))
		return (NULL);
	ft_memmove(out, s, size);
	((char *)out)[size] = '\0';
	return (out);
}

int			parse_buffer(t_last *last, t_list *chunk, char **line)
{
	ssize_t	nli;
	t_list	*old_tail;
	size_t	old_len;

	nli = ft_memchri(chunk->text, '\n', chunk->len);
	if (nli == -1)
		return (0);
	old_tail = (!(last->tail)) ? chunk : last->tail;
	old_len = (!old_tail || !old_tail->next) ? chunk->len : old_tail->len;
	ft_lstappend_back_null(last, chunk);
	last->tail->len = nli;
	if (!(*line = ft_lstjoin(&(last->head), line)))
		return (ft_lstclear_(&(last->head)));
	old_tail->next = NULL;
	if (last->head != last->tail)
		ft_lstclear_(&(last->head));
	last->head = last->tail;
	last->head->len = old_len - nli - 1;
	ft_memmove(last->head->text, last->head->text + nli + 1, old_len - nli);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static t_last	last;
	t_list			*chunk;
	ssize_t			bytes_read;
	ssize_t			res;

	if (BUFFER_SIZE == 0 || fd < 0 || line == NULL)
		return (-1);
	if (last.head != NULL && (res = parse_buffer(&last, last.head, line)) != 0) 
		return (res);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		if (!(chunk = ft_lstnew_(BUFFER_SIZE)))
			return (ft_lstclear_(&(last.head)));
		if ((bytes_read = read(fd, chunk->text, BUFFER_SIZE)) < 0)
			return (ft_lstclear_(&(last.head)));
		chunk->len = bytes_read;
		if ((res = parse_buffer(&last, chunk, line)) != 0)
			return (res);
		ft_lstappend_back_null(&last, chunk);
	}
	if (!(*line = ft_lstjoin(&(last.head), line)))
		return (ft_lstclear_(&(last.head)));
	ft_lstclear_(&(last.head));
	return (0);
}
