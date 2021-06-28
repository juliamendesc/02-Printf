
#include "ft_printf.h"


int	ft_is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (1);
	return (0);
}

int	ft_which_type(char c)
{
	if (c == 'c' || c == 's'|| c == 'p'|| c == 'd'|| c == 'i' || c == 'u'
		|| c == 'x'|| c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_flag_dot(const char *format, int i, t_flags *tab, va_list args)
{
	if (format[++i] == '*')
	{
		tab->dot = va_arg(args, int);
		i++;
	}
	else
	{
		tab->dot = 0;
		while (ft_isdigit(format[i]))
			tab->dot = (tab->dot *10) + (format[i++] - '0');
	}
	if (tab->dot >= 0)
		tab->zero = 0;
	return (i);
}

t_flags	ft_flag_minus(t_flags tab)
{
	tab.minus = 1;
	tab.zero = 0;
	return (tab);
}