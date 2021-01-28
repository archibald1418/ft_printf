#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int main ()
{
	printf("\nprintf returns %i\n", printf("|%-10.5s|", "1234567"));
	printf("\nft_printf returns %i\n", ft_printf("|%-10.5s|", "1234567"));
}
