#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <strings.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j] && little[j])
			j++;
		if (!little[j])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
/* int	main(void)
{
	const char *largestring = "s";
	const char *smallstring = "d";
	char *ptr;
	ptr = ft_strnstr(NULL, NULL, 2);
	printf("%s", ptr);
	return(0);
} */