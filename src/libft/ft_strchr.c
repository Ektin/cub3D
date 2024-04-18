#include "libft.h"
#include <stdio.h>

/* finds a character in a string an returns a pointer to the first ocurrence or NULL */

/*
** The ft_strchr() function locates the first occurrence of 'c' (converted to a
** char) in the string pointed to by 'str'. The terminating null character is
** considered to be part of the string; therefore if 'c' is '\0', the function
** locates the terminating '\0'.
**
** Returns a pointer to the located character, or NULL if the character does
** not appear in the string.
*/

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}
