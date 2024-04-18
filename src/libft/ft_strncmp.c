#include <stddef.h>
#include <stdio.h>


/**
 * Compares the first n bytes of two strings s1 and s2.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of bytes to compare.
 *
 * @return An integer greater than, equal to, or less than 0, according to whether
 *         the string s1 is greater than, equal to, or less than the string s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
