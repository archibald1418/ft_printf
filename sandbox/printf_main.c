#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int main ()
{
	printf("\nprintf returns %i\n", printf("%5d", -19));
	printf("\nft_printf returns %i\n", ft_printf("%5d", -19));
}
