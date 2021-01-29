#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int main ()
{
	printf("\nprintf returns %i\n", printf("|%.7s|\n", "h"));
	printf("\nft_printf returns %i\n", ft_printf("|%.7s|\n", "h"));

	// int c = 0;
	// printf("%s", write(1, &c, ));
}
