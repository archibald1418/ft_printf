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
	char	*arg_val;
	int		reslen; // parser return value
}				t_data;

// main func
int				ft_printf(char *fmt, ...);

// printers
int				ft_putchar_fd_(char c, int fd);
int				ft_putstr_fd_(char *s, int fd);
int				ft_putcharn (char c, size_t n);
int				ft_print_prefix(t_data *data);
void			ft_print_cs(t_data *data);
void			ft_print_diuXxp(t_data *data);
void			ft_print(t_data *data);

// utils
size_t			ft_strchri(char *fmt, int c, size_t i);
size_t			ft_alphchri(char *fmt, size_t i);
size_t			ft_ullen(unsigned long n, size_t i);
unsigned long	ft_abs(long n);
// unsigned long to ascii
char			*ft_ultoa_base(unsigned long n, int base, size_t caps);
// parser utils
void			init_parser(t_data *data);
void			cancel_zero (t_data *data);
int				is_num_type (char type);
char			get_type(char *fmt, size_t index);

// parsers
ssize_t			ft_parser(char *fmt, t_substr *substr, va_list *argptr);
size_t			parse_flags(char *fmt, size_t start, t_data *data);
size_t			parse_width (t_data *data, va_list *argptr, size_t index, char *fmt);
size_t			parse_precision (t_data *data, va_list *argptr, size_t index, char *fmt);
ssize_t			parse_type (t_data *data, va_list *argptr);

// setters
void			set_type(t_data *data, va_list *argptr);
void			set_diuXx (unsigned long num, t_data *data);
void			set_c(char c, t_data *data);
void			set_s(char *s, t_data *data);
void			set_p (unsigned long num, t_data *data);

#endif