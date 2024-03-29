/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldonita <ldonita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:01:18 by ldonita           #+#    #+#             */
/*   Updated: 2021/01/29 20:04:56 by ldonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define IS_UPPER(c) (65 <= (c) && (c) <= 90)
#define IS_UINT(t) ((t) =='x' | (t) == 'X' || (t) == 'u')
#define IS_INT(t) ((t) == 'd' | (t) == 'i')

void	set_diuxx(unsigned long num, t_data *data)
{
	char	*out;
	int		base;
	int		caps;

	base = 10;
	caps = 0;
	if (num == 0 && data->has_dot && data->prec == 0)
	{
		data->arg_val = ft_strdup("");
		return ;
	}
	if (data->type_val == 'x' || data->type_val == 'X')
	{
		base = 16;
		caps = IS_UPPER(data->type_val);
	}
	if (!(out = ft_ultoa_base(num, base, caps)))
	{
		data->arg_val = NULL;
		return ;
	}
	data->arg_val = out;
}

void	set_c(char c, t_data *data)
{
	char *out;

	if (!(out = ft_calloc(2, sizeof(char))))
	{
		data->arg_val = NULL;
		return ;
	}
	out[0] = c;
	if (data->width != 0)
		data->width -= (c == 0);
	data->arg_val = out;
	data->prec = 1;
}

void	set_s(char *s, t_data *data)
{
	char *out;

	out = NULL;
	if (s == NULL)
	{
		if (!(out = ft_strdup("(null)")))
			data->arg_val = NULL;
	}
	else if (!(out = ft_strdup(s)))
		data->arg_val = NULL;
	data->arg_val = out;
}

void	set_p(unsigned long num, t_data *data)
{
	if (num == 0 && data->has_dot && data->prec == 0)
	{
		if (!(data->arg_val = ft_strdup("")))
			return ;
	}
	else
	{
		if (!(data->arg_val = ft_ultoa_base(num, 16, 0)))
			return ;
	}
	ft_strlcpy(data->pref, "0x", 3);
}

void	set_type(t_data *data, va_list *argptr)
{
	long num;

	num = 0;
	if (data->type_val == 'p')
		set_p(va_arg(*argptr, unsigned long), data);
	else if (data->type_val == 'c')
		set_c(va_arg(*argptr, int), data);
	else if (data->type_val == 's')
		set_s(va_arg(*argptr, char *), data);
	else if (data->type_val == '%')
		set_c('%', data);
	else
	{
		if (IS_INT(data->type_val))
		{
			if ((num = va_arg(*argptr, int)) < 0)
				ft_strlcpy(data->pref, "-", 2);
		}
		else
			num = (unsigned long)va_arg(*argptr, unsigned int);
		data->is_neg = (num < 0);
		num = ft_abs(num);
		set_diuxx(num, data);
	}
}
