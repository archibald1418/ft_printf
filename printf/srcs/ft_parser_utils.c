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
	return ('\0'); // unknown type
}
