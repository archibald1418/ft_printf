#include "tests.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
// test commit

int main()
{
	// char *ptr;
	// printf("%sjhlsdakjfhdsalkjfasd %8934d  sadjkfhlkaj %%d");
	// ft_printf("alsdjfhsdkj %87349  sadjhflkj");

	printf("func returned ->%d\n", ft_printf("|===== %x %d %p =====|", 789, INT_MIN + 1, (void *)0));
	// printf("%-010%");
	// printf("1|%24p|\n", (void *)24); 
	// printf("2|%-24p|\n", (void *)24); 
	// // printf("3|%24.5p|\n", (void *)24); 
	// // printf("4|%24.0p|\n", (void *)24); 
	// printf("5|%24.p|\n", (void *)24); // prec ==0 && arg != 0 -> set prec to -1
	// printf("6|%24.p|\n", (void *)0); 
	// printf("7|%.p|\n", (void *)0); 
	// printf("8|%.p|\n", (void *)0); // prec == 0 && arg == 0 -> 0x
	// printf("8|%.p|\n", (void *)0); // prec == 0 && arg == 0 -> 0x
	// printf("9|%24p|\n", (void *)(ULONG_MAX + INT_MAX));
	// //else if (prec != 0) 
		//printf (0x0)

	// sizes of types
	// printf("%zu\n", sizeof(unsigned long));
	// printf("%zu\n", sizeof(long));
	// printf("%zu\n", sizeof(int));

	// printf("%*.*d");
	// cases with 0 as integer are weird....
	// write(1, "5", -1);
}
