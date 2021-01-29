/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:59:15 by ldonita           #+#    #+#             */
/*   Updated: 2021/01/29 19:00:49 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TYPES "cspdiuxX%"

void		cancel_zero (t_data *data)
{
	data->has_zero = 0;
	data->padding = ' ';
}

int		is_num_type (char type)
{
	return (!(type == '%' || type == 'c' || type == 's' || type == 'p'));
}

char	get_type(char *fmt, size_t index)
{
	size_t i;

	i = 0;
	while (TYPES[i] != '\0')
	{
		if (fmt[index] == TYPES[i])
			return (TYPES[i]);
		i++;
	}
	return ('\0');
}
