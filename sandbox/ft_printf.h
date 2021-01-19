#include "tests.h"
#include "libft.h"
#include <stdarg.h>

typedef struct	s_substr 
{
	ssize_t	start;
	ssize_t	end;
}				t_substr;

typedef struct	s_has_type
{
	char	type;
	int		has;
}				t_has_type;


// printers
int				ft_putchar_fd_(char c, int fd);
int				ft_putstr_fd_(char *s, int fd);

// unsigned long to ascii
char				*ft_ultoa_base(unsigned long n, int base, size_t caps);

int	ft_printf(char *fmt, ...);