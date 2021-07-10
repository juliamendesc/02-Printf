
#include "ft_printf.h"


//----------------- LIBFT UTILS -----------------------
int	ft_putchar(char c)
{
	write(1, &c, 1);
    return (1);
};

int ft_which_type(const char *format, va_list args)
{
    int		i;
	int		counter;
	t_flags	s_flags;

	i = 0;
	counter = 0;
   	if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' || format[i] == 'd' ||
       format[i] == 'i' || format[i] == 'u' || format[i] == 'x' || format[i] == 'X' || format[i] == '%')
    {

    }
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
    count += ft_which_type(format, args);
	va_end(args);
	return (count);
};

int main (void) {
	ft_printf("ola %.5s %.d %i", "string", 10, 5);
};