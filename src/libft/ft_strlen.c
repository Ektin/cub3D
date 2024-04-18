#include <stdio.h>
#include <strings.h>

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		++p;
	return (p - s);
}
/* 
int	main(void)
{
	char *str = "1234";
	printf("%lu\n", ft_strlen(str));
	printf("%lu", strlen(str));
	return (0);
} */