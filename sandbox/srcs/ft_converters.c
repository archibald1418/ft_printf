#include "ft_printf.h"
#define IS_UPPER(c) (65 <= (c) && (c) <= 90)
#define IS_UINT(t) ((t) =='x' | (t) == 'X' || (t) == 'u')
#define IS_INT(t) ((t) == 'd' | (t) == 'i')

void	set_diuXx (unsigned long num, t_data *data)
{
	char *out;
	int base;
	int caps;

	base = 10;
	caps = 0;
	if (num == 0 && data->prec == 0) //
	{
		data->arg_val = "";
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
	data->arg_val = out;
	data->prec = -1; // char deinits precision
	if (c == '%')
		data->prec = 1;
}

void	set_s(char *s, t_data *data)
{
	char *out;

	// cancel_zero(data); // string cancels zero flag
	if (s == NULL)
	{
		if (!(out = ft_strdup("(null)")))
			data->arg_val = NULL;
		return ;
	}
	else if (!(out = ft_strdup(s)))
		data->arg_val = NULL;
	data->arg_val = out;
}

void	set_p (unsigned long num, t_data *data)
{
	char *out;
	if (!(out = ft_ultoa_base(num, 16, 0)))
		data->arg_val = NULL;
	else 
	{
		data->pref = "0x"; // 0x or 0x10???
		data->arg_val = out;
		data->prec = (data->prec > -1) ? 0 : -1;
	}
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
	else {
		if (IS_INT(data->type_val))
		{
			if ((num = va_arg(*argptr, int)) < 0)
				data->pref = "-";
		}
		else
			num = va_arg(*argptr, unsigned long);
		num = ft_abs(num);
		set_diuXx(num, data);
	}
}



