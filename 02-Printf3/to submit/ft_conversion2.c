#include "ft_printf.h"

void	ft_convert_hexadecimal_lower(t_tab *tab)
{
	unsigned int	num;

	num = va_arg(*tab->args, unsigned int);
	tab->total_length += ft_putnbrBase(num, "0123456789abcdef");
}

void	ft_convert_pointer(t_tab *tab)
{
	unsigned long	pointer_value;

	pointer_value = va_arg(*tab->args, unsigned long);
	if (pointer_value == 0)
		tab->total_length += write(1, "0x0", 3);
	else if (pointer_value != 0)
	{
		tab->total_length += write(1, "0x", 2);
		tab->total_length += ft_putnbrBase(pointer_value, "0123456789abcdef");
	}
}
