/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 04:59:24 by ldonita           #+#    #+#             */
/*   Updated: 2021/01/20 20:00:02 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew_(size_t len)
{
	t_list *new;
	size_t i;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->text = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	new->len = len;
	i = 0;
	while (i <= len)
	{
		(new->text)[i] = '\0';
		i++;
	}
	new->next = NULL;
	return (new);
}

void	ft_lstappend_back_null(t_last *last, t_list *node)
{
	if (node == NULL)
		return ;
	if (last->head == NULL)
	{
		last->head = node;
		last->tail = node;
		return ;
	}
	last->tail->next = node;
	node->next = NULL;
	last->tail = node;
}

ssize_t	ft_lstclear_(t_list **lst)
{
	t_list *current;
	t_list *next;

	current = *lst;
	while (current)
	{
		next = current->next;
		free(current->text);
		current->text = NULL;
		free(current);
		current = NULL;
		current = next;
	}
	*lst = NULL;
	return (-1);
}

char	*ft_lstjoin(t_list **phead, char **line)
{
	t_list	*node;
	char	*pline;
	size_t	sumlen;

	node = *phead;
	sumlen = 0;
	while (node)
	{
		sumlen += node->len;
		node = node->next;
	}
	if (!(*line = malloc(sizeof(char) * (sumlen + 1))))
		return (NULL);
	node = *phead;
	pline = *line;
	while (node)
	{
		ft_memmove(pline, node->text, node->len);
		pline += node->len;
		node = node->next;
	}
	*pline = '\0';
	return (*line);
}
