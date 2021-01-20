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
	t_substr *substr;
	va_list args;
	t_substr	*substr;
	char *tmp;
	size_t	i;
	
	va_start(args, fmt);

	if (!(substr = malloc(sizeof(t_substr))))
		return (-1);
	ft_substr_init(substr);
	i = substr->start;
	while (fmt[i] != '\0')
	{
		if (find_specs(fmt, substr) == 1)
			if (!(tmp = ft_substr(substr->start, substr->end, substr->end - substr->start)))
				return (ft_substr_clear(substr));
			// call parser
			// write parsed string
		else
			write(1, &fmt[i], substr->end - substr->start);
		i = substr->end + 1;
	}
	va_end(args);
}