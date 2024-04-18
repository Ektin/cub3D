#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Converts an integer to a string.
 * 
 * If the integer is 0, returns a string containing "0".
 * If the integer is -2147483648, returns a string containing "-2147483648".
 * Otherwise, returns a string containing the integer.
 * 
 * @param n The integer to be converted to a string.
 * @return A string representation of the integer.
 */

int	ft_countdigit(int n)
{
	int	i;

	if (n == 0)
		return 1;
	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_convert(char *str, int n, int len)
{
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n != 0 && len > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0)
		return(ft_strndup("0", 1));
	if (n == -2147483648)
		return(ft_strndup("-2147483648", 11));
	len = ft_countdigit(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str = ft_convert(str, n, len);
	return (str);
}
