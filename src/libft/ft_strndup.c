#include "libft.h"
#include <stdlib.h>

/*
** The ft_strndup() function duplicates the string s1 up to n characters.
** The duplicated string is allocated with malloc(3).
** If the allocation fails, the function returns NULL.
** Otherwise, it returns a pointer to the duplicated string.
*/

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;

	str = malloc(n + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, n + 1);
	return (str);
}
