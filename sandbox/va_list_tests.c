#include "ft_printf.h"

void put_strarg(char *str, ...)
{
	va_list args;

	va_start(args, str);

	printf("putstr returned -> %d", ft_putstr_fd_(va_arg(args, char ), 1));

	va_end(args);
}

int main()
{
	put_strarg("abc", "**********");

	// "%d" -> ultoa
	// "%s" -> putstr
	// "%i" -> ultoa
	// "%X" -> ultoa
	// "%x" -> ultoa
	// "%p" -> ultoa
}