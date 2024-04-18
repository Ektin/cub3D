#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Removes leading and trailing characters specified in 'set' from the string 's1'.
 *
 * Parameters:
 * - s1: The input string from which to remove the characters.
 * - set: A string containing characters to be removed from the start and end of 's1'.
 *
 * Steps:
 * 1. Check for characters from 'set' at the beginning of 's1' and move the front pointer 'f' accordingly.
 * 2. Check for characters from 'set' at the end of 's1' and adjust the rear pointer 'r' accordingly.
 * 3. If all characters in 's1' are in 'set', return an empty string.
 * 4. Otherwise, allocate memory for the trimmed string and copy the relevant portion from 's1'.
 *
 * Returns:
 * - A new string with leading and trailing characters specified in 'set' removed. 
 *   If the allocation fails, returns NULL.
 * - If all characters of 's1' are in 'set', returns an empty string.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*nstr;
	int		s1len;
	int		f;
	int		r;

	s1len = ft_strlen(s1);
	f = 0;
	r = s1len;
	while (ft_strchr(set, s1[f]) != NULL && s1[f])
		f++;
	if (f == s1len)
	{
		nstr = malloc(1);
		if (!nstr)
			return (NULL);
		*nstr = '\0';
		return (nstr);
	}
	while (ft_strchr(set, s1[r - 1]) != NULL && r > f)
		r--;
	nstr = malloc(r - f + 1);
	if (!nstr)
		return (NULL);
	ft_strlcpy(nstr, s1 + f, r - f + 1);
	return (nstr);
}
/* 
int	main(void)
{
	const char *s1 = "         ";
	const char *set = " ";
	char *dst;
		
	dst = ft_strtrim(s1, set);
	while(*dst)
		{
			printf("%c", *dst);
			dst++;
		}
	return (0);
} */