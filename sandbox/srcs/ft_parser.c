#include "ft_printf.h"
#include "tests.h" // TODO: UDOLI
#define IS_FLAG(c) ((c) == '0' || (c) == '-')
#define ABS(x) (((x) >= 0) ? (x) : (x) * (-1))
#define TYPES "cspdiuxX%"

void		init_parser(t_data *data)
{
	data->padding = ' ';		// '', 0, -
	data->has_minus = 0;
	data->has_zero = 0;
	data->width = 0;		// 0
	data->prec = -1;			// 0 ->  
	data->pref = "";	// "", "-", "0x" -> 0x10
	data->type_val = '\0';
	data->type_arg = "";	// 
	data->reslen = 0;		// 
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
	return ('\0'); // unknown type
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
	} else if (ft_isdigit(fmt[index])){
		data->width = ft_atoi(&fmt[index]); // TODO: test width == 0 if not present
		ullen = ft_ullen(data->width, 0);
	}
	if (data->width < 0)
	{
		data->has_minus = 1;
		data->has_zero = 0;
		data->width = ABS(data->width); // INT_MIN stays negative, but write will write nothing))
	}
	if (data->has_zero)
		data->padding = '0';
	return (index + ullen);
}

size_t		parse_precision(t_data *data, va_list *argptr, size_t index, char *fmt)
{
	;
	return (index);
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
	ft_print_data(&data);

	if (substr->start == '.')
		substr->start = parse_precision(&data, argptr, substr->start, fmt);
	
	return (0);
	// parse_flags
}