#include "ft_printf.h"
#define IS_FLAG(c) ((c) == '0' || (c) == '-')
#define TYPES "cspdiuxX%"

static char	get_type(char *fmt, size_t index)
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

static size_t	parse_flags(char *fmt, size_t start, t_data *data)
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

static void		init_parser(t_data *data)
{
	data->padding = '\0';		// '', 0, -
	data->has_minus = 0;
	data->has_zero = 0;
	data->width = 0;		// 0
	data->prec = 0;			// 0 ->  
	data->pref = "\0\0\0";	// "", "-", "0x"
	data->type_val = '\0';
	data->type_arg = NULL;	// 
	data->reslen = 0;		// 
}

ssize_t			ft_parser (char *fmt, t_substr *substr)
{
	t_data	data;

	init_parser(&data);
	if ((data.type_val = get_type(fmt, substr->end)) == '\0')
		return (-1);
	return (0);
	// parse_flags
}