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

static size_t	ft_alphchri(char *fmt, size_t i)
{

	while ((!ft_isalpha(fmt[i]) && fmt[i] != '%') && \
	(fmt[i] != '\0' || !IS_SPACE(fmt[i])))
		i++;
	return (i);
}

int	find_specs(char *fmt, t_substr *substr) // TODO: init substr outside
{	
	// size_t	perci;

	substr->start = substr->end;
	substr->end = ft_strchri(fmt, '%', substr->start);
	if (!fmt[substr->end])
		return (0);
	substr->start += substr->end + 1;
	substr->end = ft_alphchri(fmt, substr->start); // type check will be later
	if (!fmt[substr->end] || IS_SPACE(fmt[substr->end]))
		return (0);
	return (1);
}

// int main()
// {
// 	t_substr	*substr;
// 	int out;
// 	char *fmt;

// 	char *fmt1 = "<some junk> %% <more junk>";
// 	char *fmt2 = "8479vbfhlajbflk.jz blkzjbdk.a   %%%%%%% c asdjhflajk %%";

// 	fmt = fmt2;
// 	if (!(substr = malloc(sizeof(t_substr))))
// 		return (-1);
// 	out = find_specs(fmt, substr);
// 	if (out == 0)
// 		return (0);
// 	else
// 		write(1, ft_substr(fmt, substr->start, substr->end), substr->end - substr->start);
// }