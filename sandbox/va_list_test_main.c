#include "ft_printf.h"

void put_strarg(int f, ...)
{
	va_list args;

	va_start(args, f);

	printf("\nprintf returned %d", printf("putchar returned -> %d", ft_putchar_fd_(va_arg(args, int), 1)));

	va_end(args);
}

int main()
{
	put_strarg('8', '9');

	// "%d" -> ultoa
	// "%s" -> putstr
	// "%i" -> ultoa
	// "%X" -> ultoa
	// "%x" -> ultoa
	// "%p" -> ultoa
}