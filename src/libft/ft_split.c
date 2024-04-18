#include "libft.h"
#include <stddef.h> 
#include <stdio.h>
#include <stdlib.h>

int	ft_wcount(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		k;
	int		count;

	k = 0;
	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (ft_wcount(s, c) + 1));
	if (!array)
		return (NULL);
	while (*s)
	{
		count = 0;
		while (*s != c && *s)
		{
			count++;
			s++;
		}
		if (count > 0)
			array[k++] = ft_strndup(s - count, count);
		if (*s)
			s++;
	}
	array[k] = NULL;
	return (array);
}
/* 
int	main(void)
{
	char		**dest;
	const char	*s;
	char		c;
	int			i;
	int			j;

	s = ".lolo.";
	c = '.';
	dest = ft_split(s, c);
	i = 0;
	while (dest[i])
	{
		j = 0;
		while (dest[i][j])
		{
			printf("%c", dest[i][j]);
			j++;
		}	
		printf("\n");
		i++;
	}
	return (0);
}
 */