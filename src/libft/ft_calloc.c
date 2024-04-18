#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * Allocates memory for an array of `count` elements of `size` bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero. If `count` or `size` is 0, then `ft_calloc()` returns a pointer to a zero-sized memory block.
 * If the multiplication of `count` and `size` overflows, `ft_calloc()` returns `NULL`.
 * 
 * @param count The number of elements to allocate memory for.
 * @param size The size of each element.
 * @return void* A pointer to the allocated memory block, or `NULL` if the allocation fails.
 */

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	test;

	if (count == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	test = count * size;
	if (test / count != size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

