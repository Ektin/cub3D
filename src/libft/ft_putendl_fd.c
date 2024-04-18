#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			write(fd, s++, 1);
		write(fd, "\n", 1);
	}
}
/* 
int	main(void)
{
	ft_putstr_fd("hello World", 1);
	return (0);
} */