#include "ft_printf.h"
#define IS_SPACE(c) ((c) == 32 || (9 <= (c) && (c) <= 13))

static char	*ft_alphchr(char *pfmt)
{
	while ((!ft_isalpha(*pfmt) && *pfmt != '%') && \
	(*pfmt != '\0' || !IS_SPACE(*pfmt)))
		pfmt++;
	if (*pfmt == '\0' || IS_SPACE(*pfmt))
		return (NULL);
	return (pfmt);
}

int	find_specs(char *pfmt, t_substr *substr) // TODO: init substr outside
{	
	char *perc;
	char *alpha_perc;
	char *ptr;

	ptr = pfmt;
	substr->start = substr->end;
	perc = ft_strchr(ptr, '%');
	if (!perc)
	{
		substr->end = perc - pfmt;
		return (0);
	}
	substr->start = perc - pfmt;
	ptr = perc + 1;
	alpha_perc = ft_alphchr(ptr); // type check will be later
	if (!alpha_perc)
	{
		substr->end = pfmt - alpha_perc
		return (0);
	}
	substr->end = alpha_perc + 1 - pfmt;
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