#include "ft_printf.h"

void	ft_convert_char(t_tab *tab)
{
	char	c;

	c = va_arg(*tab->args, int);
	tab->total_length += ft_putchar(c);
}

void	ft_convert_string(t_tab *tab)
{
	char	*str;

	str = va_arg(*tab->args, char *);
	if (!str)
		str = "(null)";
	tab->total_length += ft_putstr(str);
}

void	ft_convert_number(t_tab *tab)
{
	int		digit;
	char	*converted_string;

	digit = va_arg(*tab->args, int);
	converted_string = ft_itoa(digit);
	tab->total_length += ft_putstr(converted_string);
	free(converted_string);
}

void	ft_convert_unsigned_number(t_tab *tab)
{
	int		digit;
	char	*converted_string;

	digit = va_arg(*tab->args, int);
	converted_string = ft_utoa(digit);
	tab->total_length += ft_strlen(converted_string);
	write(1, converted_string, ft_strlen(converted_string));
	free(converted_string);
}

void	ft_convert_hexadecimal_upper(t_tab *tab)
{
	unsigned int	num;

	num = va_arg(*tab->args, unsigned int);
	tab->total_length += ft_putnbrBase(num, "0123456789ABCDEF");
}
