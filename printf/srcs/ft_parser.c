/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:00:55 by ldonita           #+#    #+#             */
/*   Updated: 2021/01/29 20:23:22 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define IS_FLAG(c) ((c) == '0' || (c) == '-')

size_t		parse_flags(char *fmt, size_t start, t_data *data)
{
	while (IS_FLAG(fmt[start]))
	{
		if (fmt[start] == '-')
			data->has_minus = 1;
		else
			data->has_zero = 1;
		start++;
	}
	data->has_zero = data->has_zero && !(data->has_minus);
	return (start);
}

size_t		parse_width(t_data *data, va_list *argptr, size_t index, char *fmt)
{
	size_t ullen;

	ullen = 0;
	if (fmt[index] == '*')
	{
		data->width = va_arg(*argptr, int);
		ullen = 1;
	}
	else if (ft_isdigit(fmt[index]))
	{
		data->width = ft_atoi(&fmt[index]);
		ullen = ft_ullen(data->width, 0);
	}
	if (data->width < 0)
	{
		data->has_minus = 1;
		data->has_zero = 0;
		data->width = ft_abs(data->width);
	}
	if (data->has_zero)
		data->padding = '0';
	return (index + ullen);
}

size_t		parse_precision(t_data *data,\
							va_list *argptr,\
							size_t index,\
							char *fmt)
{
	size_t	ullen;
	int		arg;

	data->prec = 0;
	data->has_dot = 1;
	ullen = 1;
	arg = 0;
	if (fmt[index] == '*')
	{
		arg = va_arg(*argptr, int);
	}
	else if (ft_isdigit(fmt[index]))
	{
		arg = ft_atoi(&fmt[index]);
		ullen = ft_ullen(arg, 0);
	}
	data->prec = arg;
	data->has_dot = (data->prec >= 0);
	if (is_num_type(data->type_val))
	{
		if (data->prec >= data->width)
			data->width = 0;
	}
	return (index + ullen);
}

ssize_t		parse_type(t_data *data, va_list *argptr)
{
	set_type(data, argptr);
	if (data->arg_val == NULL)
		return (-1);
	return (1);
}

ssize_t		ft_parser(char *fmt, t_substr *substr, va_list *argptr)
{
	t_data	data;
	size_t	reslen;

	reslen = 0;
	init_parser(&data);
	if ((data.type_val = get_type(fmt, substr->end)) == '\0')
		return (-1);
	substr->start++;
	substr->start = parse_flags(fmt, substr->start, &data);
	substr->start = parse_width(&data, argptr, substr->start, fmt);
	if (fmt[substr->start] == '.')
	{
		data.has_dot = 1;
		substr->start++;
		substr->start = parse_precision(&data, argptr, substr->start, fmt);
		if (is_num_type(data.type_val) && data.has_dot)
			cancel_zero(&data);
		else if (is_num_type(data.type_val) && !data.has_dot)
			data.prec = 1;
	}
	if (parse_type(&data, argptr) == -1)
		return (-1);
	ft_print(&data);
	free(data.arg_val);
	return (data.reslen);
}
