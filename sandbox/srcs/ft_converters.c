#include "ft_printf.h"

void	set_diuXx (unsigned long num, t_data *data)
{
	char *out;
	int base;
	int caps;

	base = 10;
	if (data->type_arg == 'x' || data->type_arg == 'X')
	{
		base = 16;
		caps = ft_isupper(data->type_arg);
	}
	if (!(out = ft_ultoa_base(num, base, caps)))
		data->type_val = NULL;
	data->type_val = out;
}

void	set_c(char c, t_data *data)
{
	char *out;

	if (!(out = ft_calloc(2, sizeof(char))))
		data->type_val = NULL;
	out[0] = c;
	data->type_val = out;
	data->prec = -1; // char or percent deinits precision
}

void	set_s(char *s, t_data *data)
{
	char *out;

	if (!(out = ft_strdup(s)))
		data->type_val = NULL;
	data->type_val = out;
}

void	set_p (unsigned long num, t_data *data)
{
	char *out;

	if (!(out = ft_ultoa_base(num, 16, 0)))
		data->type_val = NULL;
	else 
	{
		data->pref = "0x"; // 0x or 0x10???
		data->type_val = out;
		data->prec = -1; // pointers also deinits precision
	}
}

void	set_type(t_data *data, va_list *argptr)
{
	long num;

	num = 0;
	if (data->type_val == 'p')
		set_p(va_arg(*argptr, unsigned long), data);
	if (data->type_val == 'c')
		set_s(va_arg(*argptr, char), data);
	if (data->type_val == 's')
		set_s(va_arg(*argptr, char *), data);
	if (data->type_val == '%')
		set_c('%', data);
	else
	{
		num = va_arg(*argptr, long);
		if (num < 0)
		{
			data->pref = '-';
			num *= -1;
		}
		set_diuXx(num, data);
	}
}



