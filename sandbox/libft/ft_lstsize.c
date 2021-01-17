#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int i;
	t_list *tmp;

	tmp = lst;
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i + 1);
}