#include "libft.h"
#include <stddef.h>
#include <stdio.h>

/**
 * Copies 'n' bytes from memory area 'src' to memory area 'dest'. 
 * Unlike memcpy, this function is safe to use when the 'src' and 
 * 'dest' memory regions overlap, thanks to its conditional 
 * direction of copying. If 'dest' is located before 'src', it copies 
 * from the start; otherwise, it copies backwards from the end.
 * 
 * Special Case: 
 * If both 'dest' and 'src' are NULL, and 'n' is non-zero, 
 * the function returns NULL without performing any copy.
 * 
 * Returns a pointer to the destination memory area 'dest'.
 */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	i = (int)n;
	d = (char *)dest;
	s = (char *)src;
	if ((dest == NULL && src == NULL) && n != 0)
		return (NULL);
	if (d < s)
		return (ft_memcpy(dest, src, n));
	while (--i >= 0)
		d[i] = s[i];
	return (dest);
}
/*
int	main(void)
{
	char	dest[];
	char	src[];

	dest[] = "wonderfulllllllll";
	src[] = "111111111111111111";
	ft_memcpy(dest, src, 10);
	return (0);
}
*/