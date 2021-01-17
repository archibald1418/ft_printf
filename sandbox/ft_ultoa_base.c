#include "libft.h"

static size_t		is_neg(unsigned long n)
{
	if (n < 0)
		return (1);
	return (0);
}

static void			fill_digits(unsigned long n, char *str)
{
	if (n >= 10)
	{
		fill_digits(n / 10, str - 1);
		fill_digits(n % 10, str);
	}
	else
		*str = n + '0';
}

static size_t		count_digits(unsigned long n, size_t i)
{
	if (n == 0 && i == 0)
		return (1);
	if (n == 0)
		return (i);
	return (count_digits(n / 10, i + 1));
}

char				*ft_ultoa_base(unsigned long n) // original printf overflows because of such exact typing
{
	char			*out;
	size_t			ndigits;

	ndigits = count_digits(n, 0);
	out = ft_calloc(ndigits + 1, 1);
	if (out != NULL)
		fill_digits(n, out + ndigits - 1);
	return (out);
}
