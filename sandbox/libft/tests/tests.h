#ifndef TESTS_H
# define TESTS_H

# include "header.h"

typedef struct	s_last
{
	t_list	*host;
	t_list	*last;
}				t_last;

// Memes
void	test_ft_memset(void);
void	test_ft_bzero(void);
void	test_ft_memcpy(void);
void	test_ft_memccpy(void);
void	test_ft_memmove(void);
void	test_ft_memchr(void);
void	test_ft_memcmp(void);
// Strs
void	test_ft_strlen(void);
void	test_ft_strlcpy(void);
void	test_ft_strlcat(void);
void	test_ft_strchr(void);
void	test_ft_strrchr(void);
void	test_ft_strnstr(void);
void	test_ft_strncmp(void);
// ASCII
void	test_ft_atoi(void);
void    test_ft_isalnum(void);
void    test_ft_isalpha(void);
void    test_ft_isascii(void);
void    test_ft_isdigit(void);
void    test_ft_isprint(void);
void    test_ft_tolower(void);
void    test_ft_toupper(void);
// Malloc
void    test_ft_calloc(void);
void    test_ft_strdup(void);
// Additional
// Strings
void    test_ft_substr(void);
void    test_ft_strjoin(void);
void    test_ft_strtrim(void);
void    test_ft_split(void);
void    test_ft_itoa(void);
void    test_ft_strmapi(void);
// File descriptors
void    test_ft_putchar_fd(void);
void    test_ft_putstr_fd(void);
void    test_ft_putendl_fd(void);
void    test_ft_putnbr_fd(void);

// LINKED LISTS
void test_ft_lstnew(void);
void test_ft_lstadd_front(void);
void test_ft_lstsize(void);
void test_ft_lstlast(void);
void test_ft_lstadd_back(void);
void test_ft_lstdelone(void);
void test_ft_lstclear(void);
void test_ft_lstiter(void);
void test_ft_lstmap(void);

// Extra test funcs
	// Misc
void	ft_putint(int nb);
void	ft_putnbr(long nb);
void	ft_putnewline(void);
void	ft_putchar(char c);
void	ft_delineate(char *str);
size_t	ft_strsize(char *str);
void	ft_putcharvals(char *str, size_t len);
void	ft_putblock(void *ptr, size_t len, size_t count);
void	ft_putstrarr(char **arr, size_t len);
size_t  ft_count_words(char const *s, char c);
size_t  ft_iter_chars(char const *s, char sep, size_t flag);
size_t  ft_count_digits(int n, size_t i);
char			**ft_free_arr(char **arr, size_t len);
	// Linked lists
void	ft_putnode(t_list *node);
void	ft_putlist(t_list *head_node);
void	ft_fill_list_front(t_list **phead, size_t len, char **contents);
void	ft_fill_list_back(t_list **phead, size_t len, char **contents);
t_list	*ft_lstfind_node(t_list **head, char *content);
#endif
