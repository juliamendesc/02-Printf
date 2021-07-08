
#include "ft_printf.h"

static t_flags tab = {
	.dot = -1,
	.minus = 0,
	.hash = 0,
	.width = 0,
	.space = 0,
	.zero = 0,
	.plus = 0,
	.total_length = 0
};

//----------------- LIBFT UTILS -----------------------
void	ft_putchar(char c)
{
	write(1, &c, 1);
};

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = c;
	while (*s)
	{
		if (*s == a)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
	if (!a && *s == '\0')
		return ((char *)s);
	return (NULL);
}

// -------------------------- SECOND UTILS ----------------------
int ft_is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
};

int	ft_is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0); 
};

//-------------------------MAOS A OBRA-------------------------------

// int	ft_treat_flags(t_flags tab)
// {

// };

int	ft_parse_flags(const char *format, int i)
{
	while (format[i])
	{
		if (!ft_is_type(format[i]) && !ft_isdigit(format[i]) && !ft_is_flag(format[i]))
			break ; // contempla os casos de tipos que nao incluímos, como o size
		else
		{
			if (format[i] == '-')
				tab.minus = 1;
			if (format[i] == '0' && tab.minus == 0 && ((tab.dot == -1) && ft_strchr("iuxXod", format[i])))
				tab.zero = 1;
			if (format[i] == '.')
				tab.dot = 0;
			if (format[i] == '#')
				tab.hash = 1;
			if (format[i] == ' ' && tab.plus == 0)
				tab.space = 1;
			if (format[i] == '+')
				tab.plus = 1;
			if (ft_is_type(format[i]))
				break ;
		}
		i++;
	}
	return (i);
};

int	ft_printf(const char *format, ...)
{
	va_list 	args;
	int			count;
	int			i;

	i = 0;
	count = 0;
	if (!format)
		return 0;
	va_start(args, format);
	while (format[i] != '\0')
	{	
		if (format[i] == '%' && format[i + 1])
		{
			ft_parse_flags(format, ++i); // devolve o i onde começa o tipo
			// treat type conversion
		}
		if (format[i] != '%') {
			ft_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
};

int main (void) {
	ft_printf("ola %s %d %i", "string", 10, 5);
};