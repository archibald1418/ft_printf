#include "ft_printf.h"
#include "tests.h" // TODO: UDOLI
#define IS_FLAG(c) ((c) == '0' || (c) == '-')

void		init_parser(t_data *data)
{
	data->padding = ' ';		// '', 0, -
	data->has_minus = 0;
	data->has_zero = 0;
	data->width = 0;		// 0
	data->prec = -1;			// 0 ->  
	data->pref = "";	// "", "-", "0x" -> 0x10???
	data->type_val = '\0';
	data->arg_val = "";	// 
	data->reslen = 0;		// 
}

size_t	parse_flags(char *fmt, size_t start, t_data *data)
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

size_t		parse_width (t_data *data, va_list *argptr, size_t index, char *fmt)
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
		data->width = ft_atoi(&fmt[index]); // TODO: test width == 0 if not present
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

size_t		parse_precision (t_data *data, va_list *argptr, size_t index, char *fmt)
{
	size_t ullen;
	int arg;

	data->prec = 0; // at this point we have a ".", which inits precision to 0"
	ullen = 1;
	if (fmt[index] == '*')
	{
		arg = va_arg(*argptr, int);
	} else if (ft_isdigit(fmt[index])){
		arg = ft_atoi(&fmt[index]); // thik of prec == -1 
		ullen = ft_ullen(arg, 0);
	}
	data->prec = (arg < 0) ? -1 : arg; // "a negative precision is treated as though it were missing"
	if (is_num_type(data->type_val))
		cancel_zero(data);
	return (index + ullen);
}

ssize_t		parse_type (t_data *data, va_list *argptr)
{
	set_type(data, argptr);
	if (data->arg_val == NULL) // means a malloc error 
		return (-1);
	return (1);
}

ssize_t			ft_parser(char *fmt, t_substr *substr, va_list *argptr)
{
	t_data	data;
	size_t reslen;
	size_t index;

	reslen = 0;
	init_parser(&data);
	if ((data.type_val = get_type(fmt, substr->end)) == '\0')
		return (-1); // TODO: maybe write pattern as plain chars if bad specifier
	substr->start++;
	// ft_print_data(&data);
	substr->start = parse_flags(fmt, substr->start, &data);
	// ft_print_data(&data);
	substr->start = parse_width(&data, argptr, substr->start, fmt);
	// ft_print_data(&data);

	if (fmt[substr->start] == '.')
	{	
		substr->start++;
		substr->start = parse_precision(&data, argptr, substr->start, fmt);
	}
	// ft_print_data(&data);
	parse_type(&data, argptr);
	// ft_print_data(&data);
	if (data.arg_val == NULL)
		return (-1);
	ft_print(&data);
	// ft_print_data(&data);
	free(data.arg_val);
	return (data.reslen); // TODO: count write
}