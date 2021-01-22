#include "tests.h"

int		ft_is_data (t_data *data)
{
	return (data->padding &&	\
			data->has_minus &&	\
			data->has_zero &&	\
			data->width &&		\
			data->prec &&		\
			(*data->pref) &&	\
			data->type_val &&	\
			(*data->type_arg) &&\
			data->reslen);
}

void	ft_print_data (t_data *data)
{
	const int width = 21;
	if (!ft_is_data(data))
	{
		printf("padding = %*c\n", width, data->padding);
		printf("has_minus = %*d\n", width,data->has_minus);
		printf("has_zero = %*d\n", width, data->has_zero);
		printf("width = %*d\n", width, data->width);
		printf("precision = %*d\n", width, data->prec);
		printf("prefix = '%*s'\n", width, data->pref);
		printf("type value = %*c\n", width, data->type_val);
		printf("type argument = '%*s'\n", width, data->type_arg);
		printf("result length = %*d\n", width, data->reslen);
	}
	else
		printf("\n====DATA NOT PRESENT====\n");
}