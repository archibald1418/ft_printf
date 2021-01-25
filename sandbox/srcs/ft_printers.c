#include "ft_printf.h"

int	ft_putchar_fd_(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd_(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i += ft_putchar_fd_(s[i], fd);
	return (i);
}

int	ft_putcharn (char c, size_t n)
{
	size_t total;

	total = 0;
	while (n--)
		total += ft_putchar_fd_(c, 1);
	return (total);
}

int ft_print_prefix(t_data *data)
{
	return (data->reslen += write(1, data->pref, ft_strlen(data->pref)));
}
int	ft_print_cs(t_data *data)
{
	size_t i;
	size_t end;
	size_t len_padding;

	i = 0;
	end = (data->prec == -1) ? ft_strlen(data->arg_val) : data->prec;
	if (!data->has_minus)
		ft_putcharn(data->padding, data->width - end);
	while (i < end)
	{
		data->reslen += write(1, &data->arg_val[i], 1);
		i++;
	}
	if (data->has_minus)
		ft_putcharn(data->padding, data->width - end);
	return (i);
}

void	ft_print_diuXxp(t_data *data)
{
	size_t len;
	size_t len_zeros;
	size_t len_padding;
	size_t len_arg;

	len_arg = ft_strlen(data->arg_val);
	len = len_arg + ft_strlen(data->pref);
	len_zeros = (data->prec <= len) ? 0 : (data->prec - len);
	len_padding = data->width - len_zeros + len;
	data->reslen += len_padding;
	if (!data->has_minus)
		ft_putcharn(data->padding, len_padding);
	data->reslen += ft_print_prefix(data);
	data->reslen += ft_putcharn('0', len_zeros);
	data->reslen += ft_putstr_fd_(data->arg_val, 1);
	if (data->has_minus)
		ft_putcharn(data->padding, len_padding);
}
