#include "ft_printf.h"

#define FORMATS "diuXxcs"

static int ft_isin(char c)
{
	;
}

static char	*ft_alphchr(char *pfmt)
{
	while (!ft_isalpha(*pfmt) && *pfmt != '\0')
		pfmt++;
	if (pfmt == '\0')
		return (NULL);
	return (pfmt);
}

int	find_specs(char *pfmt, t_substr *substr) // TODO: init substr outside
{	
	char *perc;
	char *alpha;

	perc = ft_strchr(pfmt, '%');
	if (!perc)
		return (0);
	substr->start = perc - pfmt;
	pfmt = perc + 1;
	alpha = ft_alphchr(pfmt); // type check will be later
	if (!alpha)
		return (0);
	substr->end = alpha - pfmt;
	return (1);
}