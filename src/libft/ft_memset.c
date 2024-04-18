#include <stddef.h>

/**
 * Sets the first 'n' bytes of the memory area pointed to by 's' 
 * with the byte value 'c'. Returns a pointer to the memory area 's'.
 */

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	if (n == 0)
		return (s);
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}
/* 
int	main(void)
{
	void	*ptr[3];

	
	ft_memset(ptr, 0, 3);
	return (0);
}
 */