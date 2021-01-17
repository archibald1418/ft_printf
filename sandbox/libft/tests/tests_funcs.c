#include "header.h"
#include "tests.h"

void	ft_putint(int nb) // Uses write
{
	char out;

	out = nb + '0';
	write(1, &out, 1);
}

void	ft_putnbr(long nb) // Uses write
{
	unsigned long pos;

	if (nb < 0)
	{
		write(1, "-", 1);
		pos = nb * -1;
	}
	else if (nb >= 0)
	{
		pos = nb;
	}
	if (pos >= 10)
	{
		ft_putnbr(pos / 10);
		ft_putnbr(pos % 10);
	}
	else
	{
		ft_putint(pos);
	}
}

void	ft_putnewline(void)
{
	write(1, "\n", 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


size_t	ft_strsize(char *str)
{
	return (ft_strlen(str) + 1);
}

void	ft_putcharvals(char *str, size_t len)
{
	while (len--)
	{
		ft_putnbr((unsigned char)*str);
		str++;
		if (len > 0)
			ft_putchar(',');
	}
}

void	ft_putblock(void *ptr, size_t len, size_t count)
{
	char *str = ptr;
	size_t batchlen = len / count;
	size_t i = 0;
	while (i < batchlen)
		{
			ft_putcharvals(str, batchlen); // Prints vals and moves pointer
			if (i < (batchlen - 1))
				ft_putchar('|');
		}
	ft_putnewline();
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_delineate(char *str)
{
	size_t i = 0;
	while (i < 50)
	{
		ft_putstr(str);
		i++;
	}
}

size_t   ft_iter_chars(char const *s, char sep, size_t flag)
{
    size_t i;

    i = 0;
    while (((s[i] == sep) == flag) && (s[i] != '\0'))
        i++;
    return (i);
}

size_t   ft_count_words(char const *s, char c)
{
    size_t flag;
    size_t words;

    flag = 1;
    words = 0;
    while (*s != '\0')
    {
        s += ft_iter_chars(s, c, flag);
        if (flag == 0)
            words++;
        flag = !flag;
    }
    return (words);
}

void	ft_putstrarr(char **arr, size_t len)
{
	size_t i = 0;
	ft_putnewline();
	if (arr == NULL)
	{
		ft_putstr("|(null)|");
		return ;
	}
	while (i <= len)
	{
		printf("|%s|\n", arr[i]);
		i++;
	}
}

size_t  ft_count_digits(int n, size_t i)
{
    if (n == 0 && i == 0)
        return (1);
    if (n == 0)
        return (i);
    return (ft_count_digits(n / 10, i + 1));
}

char			**ft_free_arr(char **arr, size_t len)
{
	size_t i;

	i = 0;
	while (i <= len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ((char **)NULL);
}


void	ft_putnode(t_list *node)
{
	printf("\nNode sits at %p;\nhas value '%s';\npoints to %p\n\n", node, node->content, node->next);
}

void	ft_putlist(t_list *head_node)
{
	printf("\n>>Print linked list<<\n");
	if (head_node == NULL)
	{
		printf("\nList is NULL...\n");
		return ;
	}
	ft_delineate(".");
	while (head_node != NULL)
	{
		ft_putnode(head_node);
		head_node = head_node->next;
		if (head_node)
			ft_putstr("-> -> ->\n");
	}
	ft_delineate(".");
	printf("\nList finished\n");
	
}

void	ft_fill_list_front(t_list **phead, size_t len, char **contents)
{
	size_t i = 0;
	t_list *new_node;
	
	if (*phead == NULL)
		return ;
	while (i < len)
	{
		new_node = ft_lstnew(contents[i], ft_strsize(contents[i]));
		ft_lstadd_front(phead, new_node); 
		*phead = new_node; // Reassign the head
		i++;
	}
}



void	ft_lstappend_back(t_list **phead, t_list *node) // t_list method
{
	static t_last last; // Instead of ft_lstlast every time
	
	if ((*phead) != last.host)
	{
		last.host = *phead; 
		last.last = ft_lstlast(*phead);
	}
	ft_lstadd_back(&last.last, node);
	last.last = node;
}

void	ft_fill_list_back(t_list **phead, size_t len, char **contents)
{
	size_t i = 0;
	t_list *node;
	while (i < len)
	{
		node = ft_lstnew(contents[i], ft_strsize(contents[i]));
		ft_lstappend_back(phead, node);
		i++;
	}
}

t_list	*ft_lstfind_node(t_list **head, char *content)
{
	t_list *tmp;

	tmp = *head;
	while (tmp)
	{
		if (ft_memcmp(tmp->next->content, content, ft_strlen(content)) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}



// TODO: Function that writes to front or to back on condition
// void	ft_fill_list_both(t_lst)

