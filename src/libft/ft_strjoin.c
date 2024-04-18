#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*dst;
	
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = malloc(len1 + len2 + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, len1 + 1);
	ft_strlcpy(dst + len1, s2, len2 + 1);
	return (dst);
}
/* 
int	main(void)
{
	const char *s1 = "1234";
	const char *s2 = "abcd";
	char *dst;
		
	dst = ft_strjoin(s1, s2);
	while(*dst)
		{
			printf("%c", *dst);
			dst++;
		}
	return (0);
} */