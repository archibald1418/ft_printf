// Source files
#include "tests.h"

// Memes
#define FT_MEMSET	0
#define FT_BZERO	0
#define FT_MEMCPY	0
#define FT_MEMCCPY	0
#define FT_MEMMOVE	0
#define FT_MEMCHR	0
#define FT_MEMCMP	0

// Strings
#define FT_STRLEN	0
#define FT_STRLCPY	0
#define FT_STRLCAT	0
#define FT_STRCHR	0
#define FT_STRRCHR	0
#define FT_STRNSTR	0
#define FT_STRNCMP	0

// Literals
#define FT_ATOI		0
#define FT_ISALPHA	0
#define FT_ISDIGIT	0
#define FT_ISALNUM	0
#define FT_ISASCII	0
#define FT_ISPRINT	0
#define FT_TOUPPER	0
#define FT_TOLOWER	0

// Using malloc

#define FT_CALLOC	0
#define FT_STRDUP	0

// Additional

#define FT_SUBSTR		0
#define FT_STRJOIN		0
#define FT_STRTRIM		0
#define FT_SPLIT		0
#define FT_ITOA			0
#define FT_STRMAPI		0
#define FT_PUTCHAR_FD	0
#define FT_PUTSTR_FD	0
#define FT_PUTENDL_FD	0
#define FT_PUTNBR_FD	0

// LINKED LISTS

#define FT_LSTNEW		0
#define FT_LSTADD_FRONT	0
#define FT_LSTSIZE		0
#define FT_LSTLAST		0
#define FT_LSTADD_BACK	0
#define FT_LSTDELONE	0
#define FT_LSTCLEAR		0
#define FT_LSTITER		0
#define FT_LSTMAP		0


void	test_ft_memset(void)
{
	// For printf
	char *func = "memset";

	// Normal args
	unsigned char str1[50] = "suka,blyat";
	int c1 = '*';
	size_t len1 = 5;

	// Size equals 0
	unsigned char str2[50] = "suka;blyat";
	int c2 = '*';
	size_t len2 = 0;

	// Size bigger than string
	unsigned char str3[20] = "suka;blyat";
	int c3 = '*';
	size_t len3 = 25;

	// String is empty
	unsigned char str4[10] = "";
	int c4 = '*';
	size_t len4 = 5;
	
	// String is NULL
	unsigned char *str5 = NULL;
	int c5 = '*';
	size_t len5 = 1;

	// Char is NULL (== bzero)
	unsigned char str6[] = "suka;blyat";
	int c6 = 0;
	size_t len6 = 5;

	unsigned char *test1 = str1;
	int test2 = c1;
	size_t test3 = len1;

	printf("memset %zu bytes with %c\n", test3, test2);
	printf("old string ==> %s\n", test1);
	void *out = ft_memset(test1, test2, test3);
	printf("new string ==> %s\n", test1);

	// printf("orig %s gives%s\n", func, (char *)out);
	printf("ft_memset tests passed!\n\n");
}

void	test_ft_bzero(void)
{
	// For printf
	char *func = "memset";

	// Normal args
	unsigned char str1[50] = "suka,blyat";
	size_t len1 = 5;

	// Size equals 0
	unsigned char str2[50] = "suka;blyat";
	size_t len2 = 0;

	// Size bigger than string
	unsigned char str3[20] = "suka;blyat";
	size_t len3 = 25;



	// String is empty
	unsigned char str4[10] = "";
	size_t len4 = 5;
	
	// String is NULL
	unsigned char *str5 = NULL;
	size_t len5 = 1;

	unsigned char *test1 = str1;
	size_t test2 = len1;

	printf("bzero %zu bytes with NULL\n", test2);
	printf("old string ==> %s\n", test1);
	ft_bzero(test1, test2);
	printf("string left ==> %s\n", test1 + test2);

	// printf("orig %s gives%s\n", func, (char *)out);
	printf("ft_memset tests passed!\n\n");
}

void	test_ft_memcpy(void)
{
	// For printf
	char *func = "memcpy";

	// Size less than string
	const char src1[15] = "suka,blyat";
	size_t n1 = 5;

	// Size equals 0
	const char src2[15] = "suka;blyat";
	size_t n2 = 0;

	// Size bigger than src
	const char src3[15] = "suka;blyat";
	size_t n3 = 16;

	// src is empty
	const char src4[15] = "";
	size_t n4 = 5;
	
	// src is NULL
	const char *src5 = NULL;
	size_t n5 = 5;

	// Dst is char array
	char dst1[50];

	// Dst not empty
	char dst2[] = "********";

	void *test1 = dst1;
	const char *test2 = src1;
	size_t test3 = n3;

	printf("string to memcopy ==>%s\n", test2);
	printf("Prepare your %lu bytes to be copied to dst1\n", test3);
	printf("dst1 now lookls like this :> %s\n", ft_memcpy(test1, test2, test3));
	printf("ft_memcpy tests passed!\n\n");
}

void	test_ft_memccpy(void)
{

	// Char found in bytes
	unsigned char src1[50] = "suka;blyat";
	int c1 = ';';
	size_t n1 = 8;

	// Size equals 0
	unsigned char src2[50] = "suka;blyat";
	int c2 = ';';
	size_t n2 = 0;

	// Size bigger than srcing
	unsigned char src3[20] = "suka;blyat";
	int c3 = ';';
	size_t n3 = 25;

	// src is empty
	unsigned char src4[10] = "";
	int c4 = ';';
	size_t n4 = 6;
	
	// src is NULL
	unsigned char *src5 = NULL;
	int c5 = ';';
	size_t n5 = 1;

	// Char is NULL
	unsigned char src6[50] = "suka;blyat";
	int c6 = 0;
	size_t n6 = 5;

	// Char not in src
	unsigned char src7[50] = "suka;blyat";
	int c7 = '*';
	size_t n7 = 15;

	// Char overflow
	unsigned char src8[] = "suka;blyat";
	int c8 = 1200;
	size_t n8 = 5;

	// Char not in src and size is bigger!
	// Abort trap with orig memccpy, but abort not possible to emulate in this task
	// Abort raised if size bigger than memory allocated
	unsigned char src9[50] = "suka;blyat";
	int c9 = '*';
	size_t n9 = 155;

	// Dst is char array
	char dst1[50];

	// Dst is a string
	char dst2[] = "***********";

	char *test1 = dst1;
	unsigned char *test2 = src1;
	int test3 = c1;
	size_t test4 = n1;
	
	void *out = ft_memccpy(test1, test2, test3, test4); 
	
	printf("\nString to copy ==> \t\t%s\n", test2);
	printf("Copy until '%c' or size %lu\n", test3, test4);

	printf("dst1 now looks like this :> \t%s\n", test1);
	printf("ft_memccpy returned \t\t->%s\n", (unsigned char *)out - (out != NULL)); // Segfaults if out == NULL, so check for that

	// memccpy contains a pointer next to c
	// assert(*(cdst1 - 1) == c || cdst1 == NULL); 

	printf("ft_memccpy tests passed!\n");
}


void test_ft_memmove(void)
{
	// Size less than string
	const char src1[15] = "suka;blyat";
	size_t len1 = 5;

	// Size equals 0
	const char src2[15] = "suka;blyat";
	size_t len2 = 0;

	// Size bigger than src
	const char src3[15] = "suka;blyat";
	size_t len3 = 16;

	// src is empty
	const char src4[15] = "";
	size_t len4 = 1;
	
	// src is NULL
	const char *src5 = NULL;
	size_t len5 = 5;

	// Dst is char array
	char dst1[50];

	// Dst not empty
	char dst2[] = "********";

	// Dst is empty string
	char dst3[] = "";

	// Dst is NULL
	char *dst4 = NULL;

	// Overlap, src start
	char src6[50] = "start stop";
	char *dst6 = (src6 + 2);
	size_t len6 = sizeof(char) * 5;

	// Overlap, src end
	char src7[50] = "red rum sir is mur der";
	char *dst7 = src7 + ft_strlen(src7) - 7;
	size_t len7 = 8;

	// Overlap, src == dst
	char src8[50] = "*****;aaaaa";
	char *dst8 = src8;
	size_t len8 = sizeof(char) * 5;


	void *test1 = dst8;
	const char *test2 = src8;
	size_t test3 = len8;

	printf("\nCopying %zu bytes...\n\n", test3);
	printf("src equals \t\t%-10s\n", test2);
	printf("dst equals \t\t%s\n", test1);
	printf("ft_memmove returns \t%-10s\n", ft_memmove(test1, test2, test3));
}

void test_ft_memchr(void)
{
	// Char found
	const char *s1 = "**********f*******";
	char c1 = 'f';
	size_t n1 = 24;

	// Char is NULL
	// TODO: Check if finds end of string
	const char *s2 = "**********f*******";
	char c2 = '\0';
	size_t n2 = 30;

	// src is NULL
	const char *s3 = NULL;
	char c3 = 'f';
	size_t n3 = 24;

	// Size bigger than src, char not found
	const char s4[55] = "**********f*******";
	char c4 = '+';
	size_t n4 = 5778;
	// NOTE that this doesn't and shouldn't crash! (unlike memccpy!)


	const char *test1 = s4;
	char test2 = c4;
	size_t test3 = n4;

	void *out = ft_memchr(test1, test2, test3);

	printf("\nsrc equals \t\t%s\n", test1);
	printf("searching '%c' in first %zu bytes\n", test2, test3);
	printf("found '%c' at ->%s\n", test2, out);
	printf("%s\n", test1);
	printf("%s\n", out);
}

void test_ft_memcmp(void)
{

	// Equal
	const char *s11 = "*****";
	const char *s21 = "*****";

	// Different
	const char *s12 = "******";
	const char *s22 = "*****f";

	// >> Both strings are *assumed* to be n bytes long.
	// Should crash if different lengths? - No
	const char *s13 = "***";
	const char *s23 = "*";

	// One is NULL
	const char *s14 = "*";
	const char *s24 = NULL;
								// memcmp has no null-guards, should segfault either way
	// Both are NULL
	const char *s15 = "*";
	const char *s25 = NULL;

	const char *test1 = s13; 
	const char *test2 = s23;

	size_t n1 = ft_strlen(test2) + 1;
	size_t n2 = n1 + 1000; 

	printf("\nComparing %s and %s\n\n", test1, test2);
	printf("ft_memcmp gives %d\n", ft_memcmp(test1, test2, n2));

	// printf("orig memcmp gives %d\n", memcmp(test1, test2, n));
}

// 




void	test_ft_strlen(void)
{
	// For printf
	char *func = "strlen";

	// Normal string
	char *s1 = "abc";

	// Empty string
	char *s2 = "";

	// NULL pointer
	char *s3 = NULL;

	char *test = s1;

	printf("Count length of %s\n\n", test);
	printf("ft_%s gives %zu\n", func, ft_strlen(test));
	printf("orig %s gives %zu\n", func, ft_strlen(test));
}

void	test_ft_strlcpy(void)
{
	// For printf
	char *func = "";

	// Src string
	const char *src = "abcdegfa";
	size_t srcsize = ft_strlen(src) + 1; 

	// dstsize >= srcize
	size_t dst1size = sizeof(char) * srcsize + 10;
	char *dst1 = (char *)malloc(srcsize);

	// dstsize < srcsize
	size_t dst2size = 5;
	char *dst2 = (char *)malloc(dst2size);
	
	// Fully copied
	int out = ft_strlcpy(dst1, src, dst1size);
	assert(out < dst1size);
	printf("Fully copied! ==> %s\n", dst1);

	// Truncated, undercopied; src < dst
	out = ft_strlcpy(dst2, src, dst2size);
	assert(out >= dst2size);
	printf("Data truncated! ==> %s\n", dst2);

	printf("ft_strlcpy tests passed!\n");
	free(dst1);
	free(dst2);
}

void	test_ft_strlcat(void)
{
	const char *src1 = "abcdef";
	size_t src1size = ft_strlen(src1) + 1;

	// dstsize > srcize
	size_t dst1size = 50;
	char dst1[dst1size];

	// dstsize < srcsize
	size_t dst2size = 3;
	char dst2[dst2size];

	// dstsize == srcsize
	size_t dst3size = src1size;
	char dst3[dst3size];

	// dst not empty, dstsize > srcsize
	char dst4[50] = "000000";
	size_t dst4size = sizeof(dst4);

	// dstsize is 0
	char dst5[] = "";
	size_t dst5size = sizeof(dst5);

	// dst is NULL, should segFault
	char *dst6 = NULL;
	size_t dst6size = sizeof(dst6);

	// src is empty
	const char src2[50] = "";

	// src is NULL
	const char *src3 = NULL;

	char test1[] = "#####";
	const char *test2 = "**************";
	size_t test3 = 5;

	printf("\n\nConcat %s and %s of size %zu\n...\n", test1, test2, test3);
	size_t out = ft_strlcat(test1, test2, test3);
	printf("\ndst ==> %s\n", test1);
	printf("ft_strlcat gives %zu\n", out);
	// ft_strlcat(dst2, src, dst2size);
	// printf("Truncated concat ==> %s\n", dst2);

	// printf("ft_strlcat tests passed!\n");
	// free(dst2);
}


void	test_ft_strchr(void)
{
	// char in src
	const char src1[] = "abcdefgh";
	int c1 = (int)'#';

	// char is null
	const char *src2 = "abcdefgh";
	int c2 = (int)'\0';

	// src is null
	const char *src3 = NULL;
	int c3 = (int)'c';

	// src is empty
	const char *src4 = "";
	int c4 = (int)'c';

	// src is empty, char is null
	const char *src5 = "";
	int c5 = (int)'\0';

	// src is NULL, char is NULL
	const char *src6 = NULL;
	int c6 = (int)'\0';

	// src is empty char array
	const char src7[50];
	int c7 = 'a';

	const char *test1 = src7;
	int test2 = c7;

	printf("\nSearching for first '%c' in '%s' at %p\n", test2, test1, test1);
	char *out = ft_strchr(test1, test2);
	// printf("ft_strchr gives ==> %s at %p\nfound at %ld'th\n",out, out, out - test1 + 1);
	if (out)
		free(out);
}


void	test_ft_strrchr(void)
{
	// char in src
	const char src1[] = "abcdefgh";
	int c1 = (int)'g';

	// char is first
	const char *src2 = "abcdefgh";
	int c2 = (int)'a';

	// char is last
	const char *src3 = "abcdefgh";
	int c3 = (int)'h';

	// char is null
	const char *src4 = "abcdefgh";
	int c4 = (int)'\0';

	// src is empty
	const char *src5 = "";
	int c5 = (int)'c';

	// src is empty, char is null
	const char *src6 = "";
	int c6 = (int)'\0';

	// src is NULL, char is NULL
	const char *src7 = NULL;
	int c7 = (int)'\0';

	// src is empty char array
	const char src8[50];
	int c8 = '\0';

	// char not in src
	const char *src9 = "abcdefgh";
	int c9 = (int)'&';

	const char *test1 = src9;
	int test2 = c9;

	char *out = ft_strrchr(test1, test2);
	printf("\nSearching for last '%c' in '%s' at %p\n", test2, test1, test1);
	printf("ft_strrchr gives ==> %p\n",out);
	if (out)
		free(out);
}



void	test_ft_strnstr(void)
{
		// haystack is ok
		const char *haystack1 = "abcdefgh";
		const char *haystack2 = "aaaa";
		const char *haystack3 = "abe****abc";
		const char *haystack4 = "";

		// Test for haystack == ""

		// needle is ok
		const char *needle1 = "abc";
		const char *needle2 = "bcd";
		const char *needle3 = "h";
		const char *needle4 = "a";
		const char *needle5 = "g";
		const char *needle6 = "abcdefgh";
		
		const char *needle7 = "aa";
		const char *needle8 = "aaaa";
		const char *needle9 = "";

		const char *haystack5 = "MZIRIBMZIRIBMZE123";
		char *needle10 = "MZIRIBMZE";
		

		// len == strlen(haystack)
		size_t len1 = ft_strlen(haystack1);

		// null needle outputs whole string

		const char *test1 = "abcd";
		const char *test2 = "abcd";
		size_t test3 = 0;

		char *out = ft_strnstr(test1, test2, test3);
		// printf("\nSearching substr >>'%s'<< in string >>'%s'<<\n", test2, test1);
		// printf("in first '%zu' chars\nvvvvvvvvvvvvvvvvv\n", test3);
		printf("Found substr in %s\n", out);
		// printf("%d\n", ft_strncmp(test1, test2, ft_strlen(test1)));
		if (out)
			free(out);	

}


void	test_ft_strncmp(void)
{
	// Equal
	const char *s11 = "*****";
	const char *s21 = "*****";

	// Different
	const char *s12 = "******";
	const char *s22 = "*****f";

	// >> Both strings are *assumed* to be n bytes long.
	// Should crash if different lengths? - No
	const char *s13 = "***";
	const char *s23 = "*";

	// One is NULL
	const char *s14 = "*";
	const char *s24 = NULL;
								// memcmp has no null-guards, should segfault either way
	// Both are NULL
	const char *s15 = NULL;
	const char *s25 = NULL;

	const char *test1 = s11; 
	const char *test2 = s21;

	size_t n1 = ft_strlen(test2) + 1;
	size_t n2 = n1 + 1000; 
	size_t n3 = 10;

	size_t test3 = 8;
	// printf("\nComparing %s and %s for %zu bytes\n\n", test1, test2, test3);
	printf("ft_strncmp gives %d\n", ft_strncmp("0", NULL, 6000000));
}


void	test_ft_atoi(void)
{	
	const char *str1 = "10";
	const char *str2 = "0";
	const char *str3 = "-1";
	const char *str4 = "-12";
	const char *str5 = "+1";
	const char *str6 = "2147483647";
	const char *str7 = "-2147483648";
	const char *str8 = "-0";
	const char *str9 = "-000789fff89*";
	const char *str16 = "\v\v\t";

	// Fringe cases
	const char *str10 = "";
	const char *str11 = NULL;
	// 2**(32 + i); i = {0,1...32}
	const char *str12 = "2147483649";
	const char *str13 = "2147483647";
	const char *str14 = "-9999999999999999999";
	const char *str15 = "9999999999999999999";
	const char *str17 = "\t\v\f\r\n \f-06050";
	
	const char *test1 = str17;

	printf("ascii '%s' to integer ==> %d\n", test1, ft_atoi(test1));

}

void	test_ft_isalpha(void)
{
	int c1 = 'A';
	int c2 = 'z';
	int c3 = '\0';
	int c4 = '0';
	int c5 = 9;
	int c6 = 32;

	int test1 = c6;
	printf("ft_isalpha(%c)	with value %-3d ==> %d\n", test1, test1, ft_isalpha(test1));
}

void	test_ft_isdigit(void)
{
	int c1 = '1';
	int c2 = '9';
	int c3 = '\0';
	int c4 = 177;
	int c5 = 12;

	int test1 = c2;
	printf("ft_isdigit(%c)	with value %-3d ==> %d\n", test1, test1, ft_isdigit(test1));
}

void	test_ft_isalnum(void)
{
	int c1 = 'A';
	int c2 = 'z';
	int c3 = '\0';
	int c4 = '0';
	int c5 = '9';
	int c6 = 177;

	int test1 = c2;
	printf("ft_isalnum(%c)	with value %-3d ==> %d\n", test1, test1, ft_isalnum(test1));
}

void	test_ft_isascii(void)
{
	int c1 = '\0';
	int c2 = 127;
	int c3 = '~';
	int c4 = EOF;

	int test1 = c1;
	printf("ft_isascii(%c)	with value %-3d ==> %d\n", test1, test1, ft_isascii(test1));
}

void	test_ft_isprint(void)
{
	int c1 = '~';
	int c2 = ' ';
	int c3 = '\0';
	int c4 = '0';
	int c5 = 177;
	int c6 = 12;

	int test1 = c2;
	printf("ft_isprint(%c)	with value %-3d ==> %d\n", test1, test1, ft_isprint(test1));
}

void	test_ft_tolower(void)
{
	int c1 = '~';
	int c2 = ' ';
	int c3 = 'A';
	int c4 = 'z';

	int test1 = c3;
	printf("ft_tolower(%c)	with value %-3d ==> %c\n", test1, test1, ft_tolower(test1));
}

void	test_ft_toupper(void)
{
	int c1 = '~';
	int c2 = ' ';
	int c3 = 'A';
	int c4 = 'z';

	int test1 = c4;
	printf("ft_toupper(%c)	with value %-3d ==> %c\n", test1, test1, ft_toupper(test1));
}


void	test_ft_calloc(void)
{
	// Both not zero
	size_t count1 = 5;
	size_t size1 = 5;

	// Count is zero
	size_t count2 = 0;
	size_t size2 = 5;

	// Size is zero
	size_t count3 = 5;
	size_t size3 = 0;

	// Both are zero
	size_t count4 = 0;
	size_t size4 = 0;

	size_t test1 = 5;
	size_t test2 = 7;

	size_t len = test1 * test2;
	void *out = ft_calloc(test1, test2);
	printf("ft_calloc gives %zu objs x %zu bytes:\n", test2, test1);
	ft_putblock(out, test1, test2);
	if (out)
		free(out);
}


void	test_ft_strdup(void)
{
	const char *s1 = "abc";
	const char *s2 = "";
	const char *s3 = NULL;
	const char *s4 = "abc\0abc";

	const char *test1 = s4;
	char *out = ft_strdup(test1);
	printf("Copying string\t\t %s\n", test1);
	printf("Duplicate is now\t %s\n", out);

	assert(sizeof(out) == sizeof(strdup(test1)));
	if (out)
		free(out);
}

void	test_ft_substr(void)
{
	// char *ft_substr(char const *s, unsigned int start, size_t len);
	// Returns substring whole

	char const *s1 = "Peter piper liked pickled peppers";
	unsigned int start1 = 6;
	size_t len1 = ft_strlen("piper");
	// piper

	char const *s2 = s1;
	unsigned int start2 = 0;
	size_t len2 = ft_strlen("Peter");
	// "Peter"

	char const *s3 = s1;
	unsigned int start3 = ft_strlen(s1) - ft_strlen("peppers");
	size_t len3 = ft_strlen("peppers");
	// peppers

	// len > string
	char const *s4 = "abcd";
	unsigned int start4 = 15;
	size_t len4 = 20;

	char const *test1 = s4;
	unsigned int test2 = start4;
	size_t test3 = len4;
	
	char *out = ft_substr(test1, test2, test3); 
	printf("ft_substr(%s, %d, %zu)\ngives %s\n", test1, test2, test3, out);
	printf("charvals are:\n");
	ft_putcharvals(out, ft_strsize(out));
	if (out)
		free(out);
}


void	test_ft_strjoin(void)
{
	// NB: This concatenates strings!!

	char const *s11 = "abc";
	char const *s21 = "abc";

	char const *s12 = "***********";
	char const *s22 = "abc";

	char const *s13 = "abc";
	char const *s23 = "***********";

	char const *s14 = "\t";
	char const *s24 = "abc";

	char const *s15 = "";
	char const *s25 = "";

	char const *s16 = NULL;
	char const *s26 = NULL;
	
	char const *test1 = s13;
	char const *test2 = s23;

	char *out = ft_strjoin(test1, test2);
	printf("Joining two strings with ft_strjoin:\n");
	printf("%s\n+\n%s\n=\n%s\n", test1, test2, out);
	if (out)
		free(out);
}

void	test_ft_strtrim(void)
{
	char *s1 = "===abc===";
	char *set1 = "=";

	char *s2 = "abc";
	char *set2 = set1;

	char *s3 = "===abc";
	char *set3 = set1;
	
	char *s4 = "abc===";
	char *set4 = set1;

	char *s5 = "***@***@**abc**@***@*@*@*";
	char *set5 = "*@";

	char *s6 = "*@*abc@*@*abc*@*";
	char *set6 = set5;

	char *s7 = "abc";
	char *set7 = "abc";

	char *s8 = "   a this is a lie   a ";
	char *set8 = " a";

	char *test1 = s4;
	char *test2 = set4;

	char *out = ft_strtrim(test1, test2);
	printf("\nTrimming \"%s\"...\n\n", test1);
	printf("'%s'\nTRIM OF\n\"%s\"\nEQUALS:\n'%s'\n", test1, test2, out);
	ft_putcharvals(out, ft_strsize(out));
	if (out)
		free(out);
}

void	test_ft_split(void)
{
	const char *s1 = "    split   me  tender split me sweet   ";
	const char c1 = ' ';

	const char *s2 = "I love you";
	const char c2 = ' ';

	const char *s3 = "";
	const char c3 = 'f';

	const char *s4 = "abc\0abc   ;";
	const char c4 = ' ';

	const char *s5 = NULL;
	const char c5 = 'a';


	const char *s6 = "ne vahzno, kto sosal, vazhno, kto ebal";
	const char c6 = ' ';

	const char *test1 = s6;
	const char test2 = c6;

	printf("\nSplitting\n>>'%s'\nby\n>>'%c'\t(ascii val = %d)\n...\n\n", test1, test2, test2);
	printf(">>'%s'\nSPLIT\n>>'%c'\nEQUALS:\n", test1, test2);

	char **out = ft_split(test1, test2);
	ft_putstrarr(out, ft_count_words(test1, test2) + 1);
	if (out)
		free(out);
}



void	test_ft_itoa(void)
{
	int n1 = 15;
	int n2 = 5;
	int n3 = -5;
	int n4 = 0;
	int n5 = INT_MAX;
	int n6 = INT_MIN;
	int n7 = -99991;
	int n8 = 1;
	int n9 = 783;
	int n10 = n5 + 1;
	int n11 = n6 + 1;

	int test1 = 1;

	char *out = ft_itoa(test1);
	printf("\nConverting '%d' to ascii..\n\n", test1);
	printf("%d\nITOA\n=\n%s\n", test1, out);
	ft_putcharvals(out, ft_count_digits(test1, 0) + 1);
	free(out);
}


static char	to_stars(unsigned int i, char from){return ('*');}
static char	to_blanks(unsigned int i, char from){return ('\0');}
static char	to_spaces(unsigned int i, char from){return (' ');}
static char	to_tildes(unsigned int i, char from){return ('~');}
void	test_ft_strmapi(void)
{	
	char const *s1 = "127365";
	void *f1 = &to_stars;
	char *f1name = "to_stars";

	char const *s2 = "aaaaaaaaaaaaaaaaaa";
	void *f2 = &to_blanks;
	char *f2name = "to_blanks";

	char const *s3 = "8";
	void *f3 = &to_spaces;
	char *f3name = "to_spaces()";

	char const *s4 = "";
	void *f4 = &to_tildes;
	char *f4name = "to_tildes";

	char const *test1 = s1;
	void *test2 = f1;
	char *fname = f1name;

	printf("\nStrmapi: take func '%s()' and apply to '%s'\n", fname, test1);
	char *out = ft_strmapi(test1, test2);
	printf("\n%s\n%s(%s)\n=\n%s\n", test1, fname, test1, out);
	ft_putcharvals(out, ft_strlen(out) + 1); 
	// doesn't expose calloc-allocated strings
	
	if (ft_strncmp(fname, "to_blanks", ft_strlen("to_blanks")) == 0)
		assert(ft_strsize(out) == 1); 
	else
		assert(((ft_strsize(out) == ft_strsize((char *)test1))));
	free(out);
}


void	test_ft_putchar_fd(void)
{
	int fd1 = 0;
	int fd2 = 1;
	int fd3 = 2;
	int fd4 = -1;

	char c1 = 'a';
	char c2 = 'b';
	char c3 = 'c';
	char c4 = '\0';

	int test2 = -1;
	char test1 = c2;


	if (0 <= test2 && test2 <= 2)
	{
		printf("Writing '%c' to stdstream #%d...\n", test1, test2);
		ft_putchar_fd(test1, test2);
		printf("\nCheck the corresponding output!\n\n");
	}
	else
	{
		printf("Writing '%c' to stdstream #%d...\n", test1, test2);
		printf("FD IS BAD! ABOUT TO CRASH...\n\n");
		ft_putchar_fd(test1, test2);
	}
}


void	test_ft_putstr_fd(void)
{

	int fd1 = 0;
	int fd2 = 1;
	int fd3 = 2;
	int fd4 = -1;

	char *c1 = "a";
	char *c2 = "ba";
	char *c3 = "";
	char *c4 = NULL;

	int test2 = fd2;
	char *test1 = c2;

	if (0 <= test2 && test2 <= 2)
	{
		printf("Writing '%s' to stdstream #%d...\n", test1, test2);
		ft_putstr_fd(test1, test2);
		printf("\nCheck the corresponding output!\n\n");
	}
	else
	{
		printf("Writing '%s' to stdstream #%d...\n", test1, test2);
		printf("FD IS BAD! ABOUT TO CRASH...\n\n");
		ft_putstr_fd(test1, test2);
	}
}

void	test_ft_putendl_fd(void)
{
	int fd1 = 0;
	int fd2 = 1;
	int fd3 = 2;
	int fd4 = -1;

	char *c1 = "a";
	char *c2 = "ba";
	char *c3 = "";
	char *c4 = NULL;

	int test2 = fd2;
	char *test1 = c2;

	if (0 <= test2 && test2 <= 2)
	{
		printf("Writing '%s' & newline to stdstream #%d...\n", test1, test2);
		ft_putendl_fd(test1, test2);
		printf("\nCheck the corresponding output!\n\n");
	}
	else
	{
		printf("Writing '%s' & newline to stdstream #%d...\n", test1, test2);
		printf("FD IS BAD! ABOUT TO CRASH...\n\n");
		ft_putendl_fd(test1, test2);
	}
}

void	test_ft_putnbr_fd(void)
{
	int fd1 = 0;
	int fd2 = 1;
	int fd3 = 2;
	int fd4 = -1;

	int n1 = 15;
	int n2 = 5;
	int n3 = -5;
	int n4 = 0;
	int n5 = INT_MAX;
	int n6 = INT_MIN;
	int n7 = -99991;
	int n8 = 1;
	int n9 = 783;
	int n10 = n5 + 1;
	int n11 = n6 + 1;

	int test1 = INT_MAX;
	int test2 = fd2;

	if (0 <= test2 && test2 <= 2)
	{
		printf("Writing integer '%d' to stdstream #%d...\n", test1, test2);
		ft_putnbr_fd(test1, test2);
		printf("\nCheck the corresponding output!\n\n");
	}
	else
	{
		printf("Writing integer '%d' to stdstream #%d...\n", test1, test2);
		printf("FD IS BAD! ABOUT TO CRASH...\n\n");
		ft_putnbr_fd(test1, test2);
	}
}

void test_ft_lstnew(void)
{
	char *content = "ne ";
	t_list *node = ft_lstnew(content, ft_strsize(content));
	printf("Creating new node...\n");
	ft_putnode(node);
	ft_delineate("=");
}



void test_ft_lstadd_front(void)
{

	char *raw = "one two three four";
	char **contents = ft_split(raw, ' ');

	printf("Creating nodes...\n");


	t_list *node1; 
	node1 = ft_lstnew(contents[0], ft_strsize(contents[0]));

	t_list *node2;
	node2 = ft_lstnew(contents[1], ft_strsize(contents[1]));

	t_list *node3; 
	node3 = ft_lstnew(contents[2], ft_strsize(contents[2]));

	node1->next = node2;
	node2->next = node3;

	t_list *head_t = malloc(sizeof(t_list *));
	head_t = node1;
	t_list *head = head_t;

	ft_putlist(head);
	ft_delineate("=");

	printf("\nAdding new node up front...\n");
	t_list *node4;
	node4 = ft_lstnew(contents[3], ft_strsize(contents[3]));
	ft_lstadd_front(&head, node4);

	ft_putlist(head);
	ft_delineate("=");
}
void test_ft_lstsize(void)
{
	char *content = "ne vahzno, kto sosal, vazhno, kto ebal";
	char **contents = ft_split(content, ' ');

	size_t len = 3; // Number of words needed from contents
	t_list **phead;
	t_list *head = ft_lstnew("BEGIN TEXT", ft_strsize("BEGIN TEXT"));

	phead = &head;

	ft_fill_list_front(phead, len, contents);
	ft_putlist(*phead);

	assert(ft_lstsize(*phead) == len + 1);
}


void test_ft_lstlast(void)
{
	const char *content = "ne vahzno, kto sosal, vazhno, kto ebal";
	char **contents = ft_split(content, ' ');

	size_t len = 3; // Number of words needed from contents
	t_list **phead;
	t_list *head = ft_lstnew("BEGIN TEXT", ft_strsize("BEGIN TEXT"));

	phead = &head;

	ft_fill_list_front(phead, len, contents);
	ft_putlist(*phead);

	char *last_content = ft_lstlast(*phead)->content;
	assert(ft_strncmp(last_content, "BEGIN TEXT", ft_strlen("BEGIN TEXT")) == 0);
	ft_free_arr(contents, ft_count_words(content, ' '));
	
	// TODO: LSTCLEAR!
}
void test_ft_lstadd_back(void)
{
	char *content = "ne vahzno, kto sosal, vazhno, kto ebal";
	char **contents = ft_split(content, ' ');
	t_list *head;
	size_t len = ft_count_words(content, ' ');
	
	head = ft_lstnew("BEGIN TEXT", ft_strsize("BEGIN TEXT"));
	if (contents)
	{
		ft_fill_list_back(&head, 1, contents);
		ft_putlist(head);
	}
	else
		ft_free_arr(contents, ft_count_words(content, ' '));
}


static void	del1(void *content)
{
	ft_bzero(content, ft_strlen(content)); // Works with strs
}
void test_ft_lstdelone(void)
{
	char *content = "one two three four five six";
	char **contents = ft_split(content, ' ');

	t_list *head;
	t_list *A;
	t_list *B;
	size_t len = ft_count_words(content, ' ');
	
	head = ft_lstnew("BEGIN TEXT", ft_strsize("BEGIN TEXT"));

	ft_fill_list_back(&head, len, contents);

	printf("\nList before...\n");

	ft_putlist(head);

	char *str = "three";
	printf("\nDeleting node '%s'...\n", str);
	ft_delineate("#");
	// Delete node "three"
	A = ft_lstfind_node(&head, str);
	B = A->next;
	A->next = B->next;
	ft_lstdelone(B, &del1);
	printf("\nList after...\n");
	ft_putlist(head);
}

void test_ft_lstclear(void)
{
	const char content[] = "one two three four five six";
	char **contents = ft_split(content, ' ');

	char *start = "BEGIN TEXT";
	t_list *head = ft_lstnew(start, ft_strsize(start));
	ft_fill_list_front(&head, ft_count_words(content, ' '), contents);

	printf("\nList before...\n");
	ft_putlist(head);

	
	ft_lstclear(&head, &del1);
	ft_putlist(head); // Gives NULL
}


static void	edit2(void *content)
{
	char *new = ft_strdup("420");
	ft_bzero(content, ft_strlen(content));
	ft_memcpy(content, new, ft_strlen(new));
}
static void	edit1(void *content)
{
	ft_bzero(content, ft_strlen(content));
}

static void *edit3(void *content)
{
	ft_bzero(content, ft_strlen(content));
	ft_strlcpy(content, "#", ft_strlen("#") + 1);
	return (content);
}
void test_ft_lstiter(void)
{
	const char content[] = "1 22 333 4444 55555 666666 7777777";
	char **contents = ft_split(content, ' ');

	char *start = "BEGIN TEXT";

	t_list *head = ft_lstnew(start, ft_strsize(start));
	ft_fill_list_back(&head, 7, contents);

	ft_putlist(head); // Before
	ft_lstiter(head->next, &edit1); // Replaces first char to #
	ft_putlist(head); // After
	ft_lstclear(&head, &del1);
	
}
void test_ft_lstmap(void)
{
	const char content[] = "1 22 333 4444 55555 666666 7777777";
	char **contents = ft_split(content, ' ');

	char *start = "BEGIN TEXT";

	t_list *head = ft_lstnew(start, ft_strsize(start));
	ft_fill_list_back(&head, 7, contents);

	ft_putlist(head);

	head = ft_lstmap(head, &edit3, &del1);
	ft_putlist(head);
	// ft_lstclear(head, &del1);
}


// int main()
// {
// 	int dummy;
// // Memes
// 
// 	printf("\nTesting your awesome code...\n\n");
// 
// 	if (FT_MEMSET)
// 		test_ft_memset(); 
// 	if (FT_BZERO)
// 		test_ft_bzero(); // Uses ft_memset
// 	if (FT_MEMCPY)
// 		test_ft_memcpy();
// 	if (FT_MEMCCPY)
// 		test_ft_memccpy();
// 	if (FT_MEMMOVE)
// 		test_ft_memmove(); // Uses ft_memcpy
// 	if (FT_MEMCHR)
// 		test_ft_memchr();
// 	if (FT_MEMCMP)
// 		test_ft_memcmp();
// 
// // Strings
// 	if (FT_STRLEN)
// 		test_ft_strlen();
// 	if (FT_STRLCPY)
// 		test_ft_strlcpy(); // Uses ft_strlen
// 	if (FT_STRLCAT)
// 		test_ft_strlcat(); // Uses ft_strlen
// 	if (FT_STRCHR)
// 		test_ft_strchr();
// 	if (FT_STRRCHR)
// 		test_ft_strrchr(); // Uses ft_strlen
// 	if (FT_STRNSTR)
// 		test_ft_strnstr(); // Uses ft_strncmp, ft_strlen
// 	if (FT_STRNCMP)
// 		test_ft_strncmp(); 
// 
// // Literals
// 	if (FT_ATOI)
// 		test_ft_atoi(); // Uses ft_isdigit
// 	if (FT_ISALPHA)
// 		test_ft_isalpha();
// 	if (FT_ISDIGIT)
// 		test_ft_isdigit();
// 	if (FT_ISALNUM)
// 		test_ft_isalnum();
// 	if (FT_ISASCII)
// 		test_ft_isascii();
// 	if (FT_ISPRINT)
// 		test_ft_isprint();
// 	if (FT_TOUPPER)
// 		test_ft_toupper();
// 	if (FT_TOLOWER)
// 		test_ft_tolower();
// 
// // II. Using malloc
// 
// 	if (FT_CALLOC)
// 		test_ft_calloc();
// 	if (FT_STRDUP)
// 		test_ft_strdup();
// 
// 
// // III. 
// 	if (FT_SUBSTR)
// 		test_ft_substr();
// 	if (FT_STRJOIN)
// 		test_ft_strjoin();
// 	if (FT_STRTRIM)
// 		test_ft_strtrim();
// 	if (FT_SPLIT)
// 		test_ft_split();
// 	if (FT_ITOA)
// 		test_ft_itoa();
// 	if (FT_STRMAPI)
// 		test_ft_strmapi();
// 	if (FT_PUTCHAR_FD)
// 		test_ft_putchar_fd();
// 	if (FT_PUTSTR_FD)
// 		test_ft_putstr_fd();
// 	if (FT_PUTENDL_FD)
// 		test_ft_putendl_fd();
// 	if (FT_PUTNBR_FD)
// 		test_ft_putnbr_fd();
// 
// // LINKED LIST
// 
// 	if (FT_LSTNEW)
// 		test_ft_lstnew();
// 	if (FT_LSTADD_FRONT)
// 		test_ft_lstadd_front();
// 	if (FT_LSTSIZE)
// 		test_ft_lstsize();
// 	if (FT_LSTLAST)
// 		test_ft_lstlast();
// 	if (FT_LSTADD_BACK)
// 		test_ft_lstadd_back();
// 	if (FT_LSTDELONE)
// 		test_ft_lstdelone();
// 	if (FT_LSTCLEAR)
// 		test_ft_lstclear();
// 	if (FT_LSTITER)
// 		test_ft_lstiter();
// 	if (FT_LSTMAP)
// 		test_ft_lstmap();
// }
