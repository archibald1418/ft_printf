#include "libft.h"

#define ALPHABET "0123456789abcdef"

static void			fill_digits(unsigned long n, char *str, int base)
{
	if (n >= base)
	{
		fill_digits(n / base, str - 1, base);
		fill_digits(n % base, str, base);
	}
	else
		*str = ALPHABET[n];
}

static size_t		count_digits(unsigned long n, size_t i, int base)
{
	if (n == 0 && i == 0)
		return (1);
	if (n == 0)
		return (i);
	return (count_digits(n / base, i + 1, base));
}

char				*ft_ultoa_base(unsigned long n, int base) // original printf overflows because of such exact typing
{
	// char			*out;
	size_t			ndigits;
	char			*out;

	ndigits = count_digits(n, 0, base);
	out = ft_calloc(ndigits + 1, 1);
	fill_digits(n, (char *)out + ndigits - 1, base);
	return ((char *)out);
}
