#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main()
{
	char *s1;
	char *s2;

	s1 = (char *)ft_calloc(2, 1);
	s2 = (char *)calloc(3, 1);

	size_t i = 0;

	while (i++ < 2)
		s1[i] = '*';
	i = 0;
	while (i++ < 2)
		s2[i] = '#';

	printf("calloced -> %s", s2);
	//write(1, &s2, 4);
	//printf("ft_calloced", s1);
	
}
