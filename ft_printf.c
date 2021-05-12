#include <unistd.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 0x7f))
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

int	check_type_stdin()
{
	if ft_isdigit
}

int main (void)
{
//	int age = 100;
// 	char b = 'B';
	char sport[] = "football";

/* 	ft_putchar(b);
	ft_putchar('\n'); */
	ft_putchar(age);
	ft_putchar('\n');
/* 	ft_putnbr(age);
	ft_putchar('\n');
	ft_putstr(sport);
	ft_putchar('\n'); */

	return (0);
}