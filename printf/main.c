#include "ft_printf.h"

int main(int argc, char **argv)
{
	ft_printf("%s %s", "Hello", "World\n");
	ft_printf("%d %s and the %s %s %u\n", 99, "problems", "bitch", "aint", 1);
	ft_printf("%x%x%x%x%x  %X%X%X%X%X\n", 'H','e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd');
}
