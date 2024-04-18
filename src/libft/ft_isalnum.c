/**
 * @brief Checks whether the given character is alphanumeric.
 *
 * @param c The character to check.
 * @return 1 if the character is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}
