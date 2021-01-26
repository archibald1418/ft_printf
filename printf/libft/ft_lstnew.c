/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:20:11 by ldonita           #+#    #+#             */
/*   Updated: 2020/12/03 17:43:43 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, size_t size)
{
	t_list *new;

	new = malloc(sizeof(t_list *));
	if (new != NULL)
	{
		new->content = ft_memdup(content, size);
		new->next = NULL;
	}
	return (new);
}
