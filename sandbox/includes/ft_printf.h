#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_substr
{
	size_t	start;
	size_t	end;
}				t_substr;

typedef struct s_data
{
	char	padding; // '', 0, -
	int		has_minus;
	int		has_zero;
	int		width; // 0
	int		prec; // 0 ->  
	char	type_val;
	char	*pref; // "", "-", "0x" // FIXME: 0x -> 0x10
	char	*type_arg;
	int		reslen; // parser return value
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
size_t			ft_ullen(unsigned long n, size_t i);

ssize_t			ft_parser(char *fmt, t_substr *substr, va_list *argptr);
size_t			parse_width (t_data *data, va_list *argptr, size_t index, char *fmt);
size_t			parse_precision (t_data *data, va_list *argptr, size_t index, char *fmt);

// main func
int			ft_printf(char *fmt, ...);

#endif