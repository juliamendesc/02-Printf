
#include "ft_printf.h"

t_flags ft_init_tab(void)
{
	t_flags	tab;

	tab.dot = -1;
	tab.minus = 0;
	tab.star = 0;
	tab.type = 0;
	tab.width = 0;
	tab.zero = 0;
	return(tab);
}

int	ft_check_flags(char c)
{
	if (!ft_which_type(c) && !ft_isdigit(c) && !ft_is_flag(c))
		return (1);
	return (0);
}

int	ft_parse_flags(const char *format, int i, t_flags *tab, va_list args)
{
	while (format[i])
	{
		if (ft_check_flags(format[i]))
			break ;
		if (format[i] == '0'&& !(tab->minus) && !(tab->width))
			tab->zero = 1;
		if (format[i] == '.')
			i = ft_flag_dot(format, i, tab, args);
		if (format[i] == '-')
			*tab = ft_flag_minus(*tab);
		if (format[i] == '*')
			*tab = ft_flag_width(args, *tab);
		if (ft_isdigit(format[i]))
		{
			if (tab->star == 1)
				tab->width = 0;
			tab->width = (tab->width * 10) + (format[i] - '0');
		}
		if (ft_which_type(format[i++]))
		{
			tab->type = format[--i]; //pq?
			break ;
		}
	}
	return (i);
}

int	ft_incoming(const char *format, va_list args)
{
	int		i;
	int		count;
	t_flags	tab;

	i = 0;
	count =0;
	while (format[i])
	{
		tab = ft_init_tab();
		if (format[i] == '%' && format[i+1])
		{
			i = ft_parse_flags(format, ++i, &tab, args);
			if (ft_which_type(format[i]))
				count += ft_convert((char)tab.type, tab, args);
			else
				return (count);//verificar se nao é count += ft_putchar(format[i])
		}
		else if (format[i] != '%')
			count += ft_putchat_returnint(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list 	args;
	int			count;

	count = 0;
	va_start(args, format);
	count += ft_incoming(format, args);
	va_end(args);
	return (count);
}

int main (void) {
	ft_printf("ola %s %d %i", "string", 10, 5);
}