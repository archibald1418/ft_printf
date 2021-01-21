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
	va_list		args;
	t_substr	substr;
	size_t		total;
	char *tmp;
	
	va_start(args, fmt);

	total = 0;
	ft_substr_init(&substr);
	while (fmt[substr.end] != '\0')
	{
		substr.end = ft_strchri(fmt, '%', substr.start);
		write(1, &fmt[substr.start], substr.end - substr.start);
		substr.start = substr.end;
		if (!fmt[substr.end])
			return (total);
		substr.end = ft_alphchri(fmt, substr.start + 1);
		if (!(tmp = ft_substr(fmt, substr.start, substr.end - substr.start + 1 ))) 
			return (-1);
		// parse substr
		// check for errors
		free(tmp);
		substr.start = (substr.end += 1);
	}
	va_end(args);
	return (1);
}