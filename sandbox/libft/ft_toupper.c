/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:17:20 by ldonita           #+#    #+#             */
/*   Updated: 2020/11/21 02:46:48 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_islower(int c)
{
	if (97 <= c && c <= 122)
		return (1);
	return (0);
}

int				ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}
