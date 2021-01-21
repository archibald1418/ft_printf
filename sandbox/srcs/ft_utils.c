#include "ft_printf.h"
#define IS_SPACE(c) ((c) == 32 || (9 <= (c) && (c) <= 13))

size_t			ft_strchri(char *fmt, int c, size_t i)
{
	while (fmt[i] != '\0')
	{
		if (fmt[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (i);
}

size_t	ft_alphchri(char *fmt, size_t i)
{
	while ((!ft_isalpha(fmt[i]) && fmt[i] != '%') && \
	(fmt[i] != '\0' || !IS_SPACE(fmt[i])))
		i++;
	return (i);
}