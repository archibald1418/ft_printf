#include "tests.h"
#include <fcntl.h>

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
	int fd = open("struct.txt", O_WRONLY);

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
	dprintf(fd, "\n\n");
	if (!ft_is_data(data))
	{
		dprintf(fd, "%*s'%c'\n", -width, pad, data->padding);
		dprintf(fd, "%*s%d\n", -width, hm, data->has_minus);
		dprintf(fd, "%*s%d\n", -width, hz, data->has_zero);
		dprintf(fd, "%*s%d\n", -width, w, data->width);
		dprintf(fd, "%*s%d\n", -width, prec, data->prec);
		dprintf(fd, "%*s'%s'\n", -width, pref, data->pref);
		dprintf(fd, "%*s%c\n", -width, tv, data->type_val);
		dprintf(fd, "%*s'%s'\n", -width, ta, data->arg_val);
		dprintf(fd, "%*s%d\n", -width, rl, data->reslen);
	}
	else
		dprintf(fd, "\n====DATA NOT PRESENT====\n");
	if (fd > 0)
		close(fd);
}