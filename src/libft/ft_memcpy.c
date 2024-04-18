#include "libft.h"
#include <stddef.h>

/**
 * Copies 'n' bytes from the source memory area 'src' to the destination memory area 'dest'.
 * 
 * Parameters:
 * - dest: A pointer to the destination memory area.
 * - src: A pointer to the source memory area.
 * - n: The number of bytes to be copied.
 * 
 * Details:
 * - The function works by first casting the generic 'void*' pointers of 'dest' and 'src' to 'char*'.
 *   This casting is essential because:
 *     a. Arithmetic operations are not directly allowed on 'void*'.
 *     b. A 'char' in C represents a single byte, allowing byte-by-byte memory operations.
 * 
 * - The copying operation iterates through each byte, copying from 'src' to 'dest'.
 * 
 * - If both 'dest' and 'src' are NULL, but 'n' is non-zero, the function returns NULL.
 *   This specific behavior can be seen as a safety measure, although it's non-standard for 'memcpy'.
 * 
 * Caveat:
 * - This function does not account for memory overlap between 'dest' and 'src'. For such scenarios,
 *   consider using 'memmove' which is designed to handle overlaps.
 * 
 * Returns:
 * - A pointer to the destination memory area 'dest'.
 */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;

	dest2 = (char *)dest;
	src2 = (char *)src;
	if ((dest == 0 && src == 0) && n != 0)
		return (NULL);
	while (n--)
		*dest2++ = *src2++;
	return (dest);
}

/**
 * Copies 'n' bytes from the source memory area 'src' to the destination memory area 'dest'.
 * 
 * Parameters:
 * - dest: A pointer to the destination memory area.
 * - src: A pointer to the source memory area.
 * - n: The number of bytes to be copied.
 * 
 * Details:
 * - The function works by casting the generic 'void*' pointers of 'dest' and 'src' to 'char*'.
 *   This casting ensures byte-by-byte memory operations, given a 'char' in C represents a single byte.
 * 
 * - The copying operation iterates through each byte, copying from 'src' to 'dest'.
 * 
 * Caveat:
 * - The behavior is undefined if source and destination overlap. For handling overlaps,
 *   'memmove' should be used.
 * - The behavior is undefined if either 'src' or 'dest' is NULL.
 * 
 * Returns:
 * - A pointer to the destination memory area 'dest'.
 */
// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
//     char	*dest2;
//     char	*src2;

//     dest2 = (char *)dest;
//     src2 = (char *)src;

//     while (n--)
//         *dest2++ = *src2++;

//     return dest;
// }


