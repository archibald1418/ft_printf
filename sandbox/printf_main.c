#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int main ()
{
	ft_printf("ft ::: |%0.3d| \n", -12);
	   printf("printf ::: |%0.3d| \n", -12);
	// printf("\nprintf returns %i\n", printf("-->|%0*.*x|<--\n", 4, -4, 14));
	// printf("\nft_printf returns %i\n", ft_printf("|%.7s|\n", "h"));

	// int c = 0;
	// printf("%s", write(1, &c, ));
}
