#include "ft_printf.h"

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
	end = (!data->has_dot) ? ft_strlen(data->arg_val) : data->prec;
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

static void	init_lens (t_lens *lens, t_data *data)
{
	lens->pref = ft_strlen(data->pref);
	lens->arg = ft_strlen(data->arg_val);
	lens->total = lens->pref + lens->arg;
	lens->zeros = (data->prec > lens->total) ? data->prec - lens->total : 0;
	lens->padding = 0;
	if (data->width > (lens->total + lens->zeros)) // calc with zeros
		lens->padding = data->width  - (lens->zeros + lens->total);
}

void	ft_print_diuXxp(t_data *data)
{
	t_lens lens;
	// This accounts for ridiculously large widths

	init_lens(&lens, data);
	if (data->has_minus)
	{
		data->reslen += ft_print_prefix(lens.pref);
		data->reslen += ft_putcharn('0', lens.zeros);
		data->reslen += ft_putstr_fd_(data->arg_val, 1);
		data->reslen += ft_putcharn(data->padding, lens.padding);
	} else if (data->has_zero)
	{
		data->reslen += ft_print_prefix(lens.pref);
		data->reslen += ft_putcharn('0', lens.zeros);
		data->reslen += ft_putstr_fd_(data->arg_val, 1);
		data->reslen += ft_putcharn(data->padding, lens.padding);
	} else {
		data->reslen += ft_putcharn(data->padding, lens.padding);
		data->reslen += ft_print_prefix(lens.pref);
		data->reslen += ft_putcharn('0', lens.zeros);
		data->reslen += ft_putstr_fd_(data->arg_val, 1);
	}

	// l_pref = ft_strlen(data->pref);
	// len_arg = ft_strlen(data->arg_val);
	// len = len_arg + l_pref;
	// len_zeros = (data->prec > len) ? data->prec - len + l_pref : 0;
	// len_padding = (data->width > len) ? data->width - (len_zeros + len) : 0;
	// if (!data->has_minus)
	// {
	// 	if (data->is_neg)
	// 	{
	// 		data->reslen += ft_print_prefix(data);
	// 		data->reslen += ft_putcharn(data->padding, len_padding);
	// 	}
		
	// }
	// else if (data->has_minus)
	// {
	// 	data->reslen += ft_putcharn(data->padding, len_padding);
	// 	data->reslen += ft_print_prefix(data);
	// }
	// data->reslen += ft_putcharn('0', len_zeros);
	// data->reslen += ft_putstr_fd_(data->arg_val, 1);
	// if (data->has_minus)
	// 	data->reslen += ft_putcharn(data->padding, len_padding);
}

void	ft_print(t_data *data)
{
	if (is_num_type(data->type_val) || data->type_val == 'p')
		ft_print_diuXxp(data); // TODO: Raise malloc error
	else
		ft_print_cs(data);
}
