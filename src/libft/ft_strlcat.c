#include "libft.h"
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	a;
	size_t	srclen;

	a = 0;
	if ((dst == NULL || src == NULL) && dstsize == 0)
		return (dstsize);
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	else
		srclen += dstlen;
	while (src[a] && dstlen + 1 < dstsize)
	{
		dst[dstlen] = src[a];
		a++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (srclen);
}

// int	main(void)
// {
// 	char		dst[20] = "hello";
// 	const char	src[] = "world";

// 	printf("%zu\n", ft_strlcat(dst, src, 50));
// 	return (0);
// }