
#include "ft_printf.h"

int	ft_putchat_returnint(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_convert_char(int c, t_flags tab)
{
	int	count;

	count = 0;
	if (tab.minus)
		count += ft_putchat_returnint(c);
	count += ft_width_treat(tab.width, 1, tab.zero);
	if (!tab.minus)
		count += ft_putchat_returnint(c)
	return (count);
}