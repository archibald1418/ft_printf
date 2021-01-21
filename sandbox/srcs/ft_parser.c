#include "ft_printf.h"
#define IS_FLAG(c) ((c) == '0' || (c) == '-')

// size_t		parse_flags(char *fmt, size_t start, t_data *data)
// {
// 	while ()
// }

static void		init_parser(t_data *data)
{
	data->padding = ' ';		// '', 0, -
	data->has_minus = 0;
	data->has_zero = 0;
	data->width = 0;		// 0
	data->prec = 0;			// 0 ->  
	data->pref = "\0\0\0";	// "", "-", "0x"
	data->type_arg = NULL;	// 
	data->reslen = 0;		// 
}

ssize_t			ft_parser (char *fmt, t_substr *substr)
{
	t_data	data;

	init_parser(&data);
}