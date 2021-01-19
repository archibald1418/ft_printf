#include "ft_printf.h"

int	ft_printf(char *fmt, ...)
{
	// I can detect first candidate for format specification patterns in a format string.
	// "asdjkhflkadsjfhalk %8743259876b" -> %8743259876b
	t_substr *substr;
	int out;

	va_list args;

	va_start(args, fmt);

	// find_specs

	va_end(args);
}