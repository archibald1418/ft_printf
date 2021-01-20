#include "ft_printf.h"

static int	ft_substr_clear(t_substr *substr)
{
	free(substr);
	return (-1);
}

static void	ft_substr_init(t_substr *substr)
{
	substr->start = 0;
	substr->end = 0;
}

int	ft_printf(char *fmt, ...)
{
	t_substr	substr;
	va_list		args;
	t_substr	*substr;
	
	char *tmp;
	
	va_start(args, fmt);

	ft_substr_init(&substr);
	while (fmt[substr.end] != '\0')
	{
		if (find_specs(fmt, &substr) == 1)
			if (!(tmp = ft_substr(substr.start, substr.end, substr.end - substr.start))) // 
				return (ft_substr_clear(&substr)); // FIXME: handle errors better later
			// call parser
			// write parsed string
		else
			write(1, &fmt[substr.start], substr.end - substr.start);
		substr.start++;
	}
	va_end(args);
}