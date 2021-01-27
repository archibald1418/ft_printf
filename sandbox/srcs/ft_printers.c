#include "ft_printf.h"

int		ft_putchar_fd_(char c, int fd)
{
	return (write(fd, &c, 1));
}

int		ft_putstr_fd_(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i += ft_putchar_fd_(s[i], fd);
	return (i);
}

int		ft_putcharn (char c, size_t n)
{
	int total;

	total = 0;
	while (n--)
		total += ft_putchar_fd_(c, 1);
	return (total);
}

int		ft_print_prefix(t_data *data)
{
	return(write(1, data->pref, ft_strlen(data->pref)));
}
void	ft_print_cs(t_data *data)
{
	int		i;
	int		end;
	size_t	len_padding;
	size_t	total;

	i = 0;
	total = 0;
	end = (data->prec == -1) ? ft_strlen(data->arg_val) : data->prec;
	len_padding = (data->width >= end) ? data->width - end : 0;
	if (!data->has_minus)
		data->reslen += ft_putcharn(data->padding, len_padding);
	while (i < end)
	{
		data->reslen += write(1, &data->arg_val[i], 1);
		i++;
	}
	if (data->has_minus)
		data->reslen += ft_putcharn(data->padding, len_padding);
}

void	ft_print_diuXxp(t_data *data)
{
	int		len;
	size_t	len_zeros;
	size_t	len_padding;
	size_t	len_arg;

	len_padding = 0;
	len_arg = ft_strlen(data->arg_val);
	len = len_arg + ft_strlen(data->pref);
	len_zeros = (data->prec <= len) ? 0 : (data->prec - len);
	len_padding = (data->width > len) ? data->width - (len_zeros + len) : 0; // max(data->width, data->prec) -
	data->reslen += len_padding;
	if (!data->has_minus)
		data->reslen += ft_putcharn(data->padding, len_padding);
	data->reslen += ft_print_prefix(data);
	data->reslen += ft_putcharn('0', len_zeros);
	data->reslen += ft_putstr_fd_(data->arg_val, 1);
	if (data->has_minus)
		data->reslen += ft_putcharn(data->padding, len_padding);
}

void	ft_print(t_data *data)
{
	if (is_num_type(data->type_val) || data->type_val == 'p')
		ft_print_diuXxp(data);
	else
		ft_print_cs(data);
}
