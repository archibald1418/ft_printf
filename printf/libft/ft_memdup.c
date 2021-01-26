#include "libft.h"

void	*ft_memdup(const void *s, size_t size)
{
	void *out = malloc(size);
	if (out != NULL)
		ft_memcpy(out, s, size);
	return (out);
}