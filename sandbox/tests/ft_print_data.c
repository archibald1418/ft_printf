#include "tests.h"

int		ft_is_data (t_data *data)
{
	return (data->padding == ' '	&&	\
			data->has_minus			&&	\
			data->has_zero			&&	\
			data->width				&&	\
			(data->prec < 0)		&&	\
			(*data->pref)			&&	\
			data->type_val			&&	\
			(*data->arg_val)		&&	\
			data->reslen);		// prec==0 is significant
}

void	ft_print_data (t_data *data)
{
	const int width = 18;
	char *pad = "padding = ";
	char *hm = "has_minus = ";
	char *hz = "has_zero = ";
	char *w = "width = ";
	char *prec = "precision = ";
	char *pref = "pref = ";
	char *tv = "type value = ";
	char *ta = "arg value = ";
	char *rl = "result length = ";
	printf("\n\n");
	if (!ft_is_data(data))
	{
		printf("%*s'%c'\n",-width, pad, data->padding);
		printf("%*s%d\n", -width, hm, data->has_minus);
		printf("%*s%d\n", -width, hz, data->has_zero);
		printf("%*s%d\n", -width, w, data->width);
		printf("%*s%d\n", -width, prec, data->prec);
		printf("%*s'%s'\n", -width, pref, data->pref);
		printf("%*s%c\n", -width, tv, data->type_val);
		printf("%*s'%s'\n", -width, ta, data->arg_val);
		printf("%*s%d\n", -width, rl, data->reslen);
	}
	else
		printf("\n====DATA NOT PRESENT====\n");
}