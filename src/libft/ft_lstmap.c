#include "libft.h"

/*
** Applies the function 'f' to each element of the linked list 'lst' to create
** a new list. The 'del' function is used to delete the content of an element
** if allocation fails. The new list is returned.
**
** @param lst The linked list to iterate over.
** @param f The function to apply to each element.
** @param del The function to delete the content of an element if allocation fails.
** @return The new list, or NULL if allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	newlst = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstdelone(tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, tmp);
		lst = lst->next;
	}
	return (newlst);
}
