#include "ft_printf.h"

void	init_struct(t_tab *tab, char *format, va_list *args)
{
	tab->format = format;
	tab->args = args;
	tab->index = 0;
	tab->total_length = 0;
}

void	ft_check_type(t_tab *tab)
{
	tab->index++;
	if (tab->format[tab->index] == 'c')
		ft_convert_char(tab);
	if (tab->format[tab->index] == 's')
		ft_convert_string(tab);
	if (tab->format[tab->index] == 'p')
		ft_convert_pointer(tab);
	if (tab->format[tab->index] == 'd' || tab->format[tab->index] == 'i')
		ft_convert_number(tab);
	if (tab->format[tab->index] == 'u')
		ft_convert_unsigned_number(tab);
	if (tab->format[tab->index] == 'x')
		ft_convert_hexadecimal_lower(tab);
	if (tab->format[tab->index] == 'X')
		ft_convert_hexadecimal_upper(tab);
	if (tab->format[tab->index] == '%')
		tab->total_length += ft_putchar('%');
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_tab	tab;
	char	*copy;

	copy = ft_strdup(format);
	va_start(args, format);
	init_struct(&tab, copy, &args);
	while (format[tab.index] != '\0')
	{
		if (format[tab.index] == '%')
			ft_check_type(&tab);
		else
		{
			write(1, &format[tab.index], 1);
			tab.total_length++;
		}
		tab.index++;
	}
	va_end(args);
	free(copy);
	return (tab.total_length);
}


int	main(void)
{
	int a;
	int b;

	a = printf("\n s int max --0*   %d   *0 0* \n", INT_MAX);
	b = ft_printf("\n j int min --0*   %d   *0 0* \n", INT_MAX);
    printf("\n total printf i min %d\n", a);
    ft_printf("\n total meu printf i min %d\n\n\n", b);
	a = printf("\n s int max --0*   %d   *0 0* \n", INT_MIN);
	b = ft_printf("\n j int min --0*   %d   *0 0* \n", INT_MIN);
    printf("\n total printf i min %d\n", a);
    ft_printf("\n total meu printf i min %d\n\n\n", b);
	a = printf("\n s d max --0*   %ld   *0 0* \n", LONG_MIN);
	b = ft_printf("\n j i max --0*   %d   *0 0* \n", LONG_MIN);
    printf("\n total printf i min %d\n", a);
    ft_printf("\n total meu printf i min %d\n", b);
	a = printf("\n s d max --0*   %ld   *0 0* \n", LONG_MIN);
	b = ft_printf("\n j d max --0*   %d   *0 0* \n", LONG_MIN);
    printf("\n total printf d min %d\n", a);
    ft_printf("\n total meu printf d min %d\n\n\n", b);
	a = printf("\n s i max --0*   %i   *0 0* \n", LONG_MAX);
	b = ft_printf("\n j i max --0*   %i   *0 0* \n", LONG_MAX);
    printf("\n total printf i max %i\n", a);
    ft_printf("\n total meu printf imax %i\n\n\n", b);
	a = printf("\n s d max --0*   %i   *0 0* \n", LONG_MAX);
	b = ft_printf("\n j i max --0*   %i   *0 0* \n", LONG_MAX);
    printf("\n total printf d max %i\n", a);
    ft_printf("\n total meu printf d max %i\n\n\n", b);

}