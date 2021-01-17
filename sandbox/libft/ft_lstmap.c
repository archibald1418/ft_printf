#include "libft.h"

// FIXME! Outputs shorter list...
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *tmp;
	t_list *new_head;

	tmp = lst;
	new_head = ft_lstnew(f(lst->content), ft_strlen(f(lst->content)));
	while (tmp->next)
	{
		new = ft_lstnew(f(tmp->next->content), ft_strlen(f(tmp->next->content)));
		ft_lstadd_back(&new_head, new);
		tmp = tmp->next;
	}
	ft_lstclear(&lst, del);
	return (new_head);
}