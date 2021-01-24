#include "tests.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
// test commit

int main()
{
	// char *ptr;
	// printf("%sjhlsdakjfhdsalkjfasd %8934d  sadjkfhlkaj %%d");
	// ft_printf("alsdjfhsdkj %87349  sadjhflkj");

	printf("%zd", write(1, "89", -5)); 
	// printf("%*.*d");
	// cases with 0 as integer are weird....
	// write(1, "5", -1);
}
