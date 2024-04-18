#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*next;

	if (!lst)
		return (0);
	i = 0;
	next = lst;
	while (next)
	{
		i++;
		next = next->next;
	}
	return (i);
}
