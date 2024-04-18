#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}

/* 
int	main(void)
{
	const char s[] = "01234";
	char *dest;
	dest = ft_substr(s, 2, 2);

	while (*dest)
	{
		printf("%c", *dest);
		dest++;
	}
	return (0);
} */