#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			write(fd, s++, 1);
	}
}
/* 
int	main(void)
{
	ft_putstr_fd("hello World", 1);
	return (0);
} */