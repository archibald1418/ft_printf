#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int main ()
{
	   printf("|%*d %*x %*X %*i %*u\n", 1, 5, 10, 547, 1, 300, 10, -55, 1, -60);
	ft_printf("|%*d %*x %*X %*i %*u\n", 1, 5, 10, 547, 1, 300, 10, -55, 1, -60);
	// printf("\nprintf returns %i\n", printf("-->|%0*.*x|<--\n", 4, -4, 14));
	// printf("\nft_printf returns %i\n", ft_printf("|%.7s|\n", "h"));

	// int c = 0;
	// printf("%s", write(1, &c, ));
}
