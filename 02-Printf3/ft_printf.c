
#include "ft_printf.h"

void    init_struct(t_tab *tab, char *format, va_list *args)
{
    tab->format = format;
    tab->args = args;
    tab->index = 0;
    tab->total_length = 0;
}

void    ft_check_type(t_tab *tab)
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
        ft_convert_hexadecimal_lower(16, tab);
    if (tab->format[tab->index] == 'X')
        ft_convert_hexadecimal_upper(16, tab);
    if (tab->format[tab->index] == '%')
        tab->total_length += ft_putchar('%');
}

int     ft_printf(const char *format, ...)
{
    va_list args;
    t_tab   tab;
    char    *copy;

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

/* int     main()
{
    int a;
    int b;
    int *c;

    a = ft_printf("%s %c %d %% %u %X %x %p\n", "ola", 'l', 123, 651442, 30, 30, c);
    b = printf("%s %c %d %% %u %X %x %p\n", "ola", 'l', 123, 651442, 30, 30, c);
    
    ft_printf("%d\n", a);
    printf("%d\n", b);
}


 */