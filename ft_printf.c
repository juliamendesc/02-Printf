
#include "ft_printf.h"

t_flags tab
{
	dot = -1;
	minus = 0;
	hash = 0;
	width = 0;
	zero = 0;
	plus = 0;
	total_length = 0;
	return(tab);
}

void	ft_parse_flags(const char *format)
{
	t_flags	tab;

	ft_init_tab();
	printf("struct %d", tab.dot);
}

int	ft_printf(const char *format, ...)
{
	va_list 	args;
	int			count;

	count = 0;
	va_start(args, format);
	ft_parse_flags(format);
	//check type
	va_end(args);
	return (count);
}

int main (void) {
	ft_printf("ola %s %d %i", "string", 10, 5);
}