#include "tests.h"
#include "libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

typedef struct	s_substr 
{
	size_t	start;
	size_t	end;
}				t_substr;


typedef struct s_data
{
	int		flag; // '', 0, -
	int		width; // 0
	int		prec; // 0 ->  
	char	*pref; // "", "-", "0x"
	char	*type_arg;
	int		reslen; // return value
}				t_data;

// printers
int				ft_putchar_fd_(char c, int fd);
int				ft_putstr_fd_(char *s, int fd);

// unsigned long to ascii
char				*ft_ultoa_base(unsigned long n, int base, size_t caps);

// utils
int				find_specs(char *pfmt, t_substr *substr);
size_t			ft_strchri(char *fmt, int c, size_t i);
size_t			ft_alphchri(char *fmt, size_t i);

// main func
int			ft_printf(char *fmt, ...);