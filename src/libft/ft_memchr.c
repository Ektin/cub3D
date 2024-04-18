#include "libft.h"
#include <stddef.h>

/*
** The ft_memchr() function locates the first occurrence of 'c' (converted to an
** unsigned char) in string 's'. The search is limited to the first 'n' bytes of
** the string. If the character is found, a pointer to the character is returned.
** Otherwise, NULL is returned.
**
** s: The string to be searched.
** c: The character to be located.
** n: The maximum number of bytes to be searched.
**
** Returns: A pointer to the located character, or NULL if the character is not found.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n--)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}
