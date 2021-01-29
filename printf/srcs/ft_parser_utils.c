/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:59:15 by ldonita           #+#    #+#             */
/*   Updated: 2021/01/29 20:06:56 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define TYPES "cspdiuxX%"

void		cancel_zero(t_data *data)
{
	data->has_zero = 0;
	data->padding = ' ';
}

int			is_num_type(char type)
{
	return (!(type == '%' || type == 'c' || type == 's' || type == 'p'));
}

char		get_type(char *fmt, size_t index)
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

void		init_parser(t_data *data)
{
	data->padding = ' ';
	data->has_minus = 0;
	data->has_zero = 0;
	data->is_neg = 0;
	data->has_dot = 0;
	data->width = 0;
	data->prec = 0;
	data->pref[0] = '\0';
	data->type_val = '\0';
	data->arg_val = NULL;
	data->reslen = 0;
}
