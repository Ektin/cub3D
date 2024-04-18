#include <stddef.h>
#include <stdio.h>

/*
** Sets the first n bytes of the memory area pointed to by s to zero.
**
** s: A pointer to the memory area to be zeroed.
** n: The number of bytes to be zeroed.
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n-- > 0)
	{
		*str = '\0';
		str++;
	}
}
/* 
int	main(void)
{
	void *ptr[3];
	printf("%c\n", *str);

	ft_bzero(ptr, 3);
	return (0);
} */