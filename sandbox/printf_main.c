#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int main ()
{
	printf("\nprintf returns %i\n", printf("|%d|", 0));
	printf("\nft_printf returns %i\n", ft_printf("|%d|", 0));
}
