
#include "ft_printf.h"

int	ft_convert(char type, t_flags tab, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count = ft_convert_char(va_arg(args, int), tab);
	if (type == 's')
		count = ft_convert_string(va_arg(args, char *), tab);
	if (type == 'd' || type == 'i')
		count = ft_convert_int(va_arg(args, char *), tab);
/* 	if (type == 'x' || type == 'X' || type == 'u')
		count = //convert unsigned int
	if (type == 'p')
		count = //conver long long
	if (type == '%')
		count = //convert char */
	return (count);
}