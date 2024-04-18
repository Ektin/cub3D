#include "libft.h"
#include <stdio.h>

/*
** The ft_strdup() function allocates sufficient memory for a copy of the
** string s1, does the copy, and returns a pointer to it. The pointer may
** subsequently be used as an argument to the function free(3). If insufficient
** memory is available, NULL is returned.
**
** len: length of the string s1
** str: pointer to the newly allocated memory block
**
** Returns: a pointer to the newly allocated memory block which contains a
** copy of s1, or NULL if the allocation fails.
*/

char	*ft_strdup(const char *s1)
{
	unsigned int	len;
	char			*str;

	len = ft_strlen(s1);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}
