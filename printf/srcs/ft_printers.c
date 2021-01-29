#include "ft_printf.h"

int		ft_print_prefix(t_data *data)
{
	return(write(1, data->pref, ft_strlen(data->pref)));
}

static int	ft_strnlen(char *s, size_t n)
{
	size_t i;

	i = 0;
	while (s[i] != 0 && i < n)
		i++;
	return (i);
}

void	ft_print_cs(t_data *data)
{
	int		i;
	int		end;
	size_t	len_padding;
	size_t	total;

	i = 0;
	total = 0;
	end = 0;
	if (data->has_dot)
		end = ft_strnlen(data->arg_val, data->prec);
	else 
		end = ft_strlen(data->arg_val);
	len_padding = (data->width >= end) ? data->width - end : 0;
	if (!data->has_minus)
		data->reslen += ft_putcharn(data->padding, len_padding);
	if (data->type_val == 'c')
		data->reslen += write(1, &data->arg_val[0], 1);
	else 
		while (i < end)
		{
			data->reslen += write(1, &data->arg_val[i], 1);
			i++;
		}
	if (data->has_minus)
		data->reslen += ft_putcharn(data->padding, len_padding);
}

static void	init_lens (t_lens *lens, t_data *data)
{
	lens->pref = ft_strlen(data->pref);
	lens->arg = ft_strlen(data->arg_val);
	lens->total = lens->pref + lens->arg;
	lens->zeros = (data->prec > lens->arg) ? data->prec - lens->arg: 0;
	lens->padding = 0;
	if (data->width > (lens->total + lens->zeros))
		lens->padding = data->width  - (lens->zeros + lens->total);
}

void	ft_print_diuXxp(t_data *data)
{
	t_lens lens;

	init_lens(&lens, data);
	if (data->has_minus)
	{
		data->reslen += ft_print_prefix(data);
		data->reslen += ft_putcharn('0', lens.zeros);
		data->reslen += ft_putstr_fd_(data->arg_val, 1);
		data->reslen += ft_putcharn(data->padding, lens.padding);
	} else if (data->has_zero) {
		data->reslen += ft_print_prefix(data);
		data->reslen += ft_putcharn(data->padding, lens.padding);
		data->reslen += ft_putstr_fd_(data->arg_val, 1);
	} else {
		data->reslen += ft_putcharn(data->padding, lens.padding);
		data->reslen += ft_print_prefix(data);
		data->reslen += ft_putcharn('0', lens.zeros);
		data->reslen += ft_putstr_fd_(data->arg_val, 1);
	}

}

void	ft_print(t_data *data)
{
	if (is_num_type(data->type_val) || data->type_val == 'p')
		ft_print_diuXxp(data);
	else
		ft_print_cs(data);
}
