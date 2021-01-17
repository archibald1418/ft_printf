#include "tests.h"
#include "libft.h"
#include <stdarg.h>

// printers
int				ft_putchar_fd_(char c, int fd);
int				ft_putstr_fd_(char *s, int fd);

// unsigned long to ascii
char				*ft_ultoa_base(unsigned long n, int base);