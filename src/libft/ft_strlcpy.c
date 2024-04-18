#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
/* 
int	main(void)
{
	char		dst[];
	const char	src[];
	size_t		i;

    dst[] = "wonderful";
    src[] = "1111";
    i = 2;
    ft_strlcpy(dst, src, i);
    return(0);
}
 */