#include <unistd.h>

void	output(int n, int fd)
{
	if (n > 9)
		output(n / 10, fd);
	n = n % 10 + '0';
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0 && n != -2147483648)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	output(n, fd);
}
/* 
int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);
} 
*/