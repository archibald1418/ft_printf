#include "ft_printf.h"

static void	ft_substr_init(t_substr *substr)
{
	substr->start = 0;
	substr->end = 0;
}

static int	handle_errors(va_list *argptr)
{
	va_end(*argptr);
	return (-1);
}

int	ft_printf(char *fmt, ...)
{
	va_list		args;
	t_substr	substr;
	size_t		total;
	int			out;
	
	va_start(args, fmt);
	total = 0;
	ft_substr_init(&substr);
	while (fmt[substr.end] != '\0')
	{
		substr.end = ft_strchri(fmt, '%', substr.start);
		total += write(1, &fmt[substr.start], substr.end - substr.start);
		substr.start = substr.end;
		if (!fmt[substr.end])
			return (total);
		substr.end = ft_alphchri(fmt, substr.start + 1);
		if ((out = ft_parser(fmt, &substr, &args)) == -1)
			return (handle_errors(&args));
		total += out;
		substr.start = (substr.end += 1);
	}
	va_end(args);
	return (total);
}