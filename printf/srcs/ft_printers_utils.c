#include "ft_printf.h"

int		ft_putchar_fd_(char c, int fd)
{
	return (write(fd, &c, fd));
}

int		ft_putstr_fd_(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i += ft_putchar_fd_(s[i], fd);
	return (i);
}

int		ft_putcharn (char c, size_t n)
{
	int total;

	total = 0;
	while (n--)
		total += ft_putchar_fd_(c, 1);
	return (total);
}