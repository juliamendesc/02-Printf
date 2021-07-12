
#include "ft_printf.h"

void    ft_convert_char(t_tab *tab)
{
    char    c;

    c = va_arg(*tab->args, int);
    tab->total_length += ft_putchar(c);
}

void    ft_convert_string(t_tab *tab)
{
    char    *str;

    str = va_arg(*tab->args, char *);
    tab->total_length += ft_putstr(str);
}

void    ft_convert_number(t_tab *tab)
{
    int     digit;
    char    *converted_string;

    digit = va_arg(*tab->args, int);
    converted_string = ft_itoa(digit);
    tab->total_length += ft_putstr(converted_string);
}

void    ft_convert_unsigned_number(t_tab *tab)
{
    int     digit;
    char    *converted_string;

    digit = va_arg(*tab->args, int);
    converted_string = ft_utoa(digit);
    tab->total_length += ft_strlen(converted_string);
    write(1, converted_string, ft_strlen(converted_string));
}

void    ft_convert_hexadecimal_upper(int base, t_tab *tab) 
{
    int num;
    char *hex_scale;
    char *ptr; 
 
    hex_scale = malloc(sizeof(char) * 17);
    if (!hex_scale)
        return ;
    hex_scale = "0123456789ABCDEF";
    ptr = malloc(sizeof(char) * 1);
    num = va_arg(*tab->args, int);
    while (num != 0) 
    { 
        ptr = ft_strjoinchr(ptr, hex_scale[num%base]); //de trás pra frente
        num /= base; 
    }
    tab->total_length += ft_strlen(ptr);
    ft_reverse_string(ptr, 0, ft_strlen(ptr));
    write(1, ptr, sizeof(ptr));
}

void    ft_convert_hexadecimal_lower(int base, t_tab *tab) 
{
    int num;
    char *hex_scale;
    char *ptr; 
 
    hex_scale = malloc(sizeof(char) * 17);
    if (!hex_scale)
        return ;
    hex_scale = "0123456789abcdef";
    ptr = malloc(sizeof(char) * 1);
    num = va_arg(*tab->args, int);
    while (num != 0) 
    { 
        ptr = ft_strjoinchr(ptr, hex_scale[num%base]); //de trás pra frente
        num /= base; 
    }
    tab->total_length += ft_strlen(ptr);
    ft_reverse_string(ptr, 0, ft_strlen(ptr));
    write(1, ptr, sizeof(ptr));
}

void    ft_convert_pointer(t_tab *tab)
{
    unsigned long pointer_value;
 
    pointer_value = va_arg(*tab->args, unsigned long);
    if (pointer_value == 0)
        tab->total_length += write(1, "0x0", 3);
    else if (pointer_value != 0)
    {   
        tab->total_length += write(1, "0x", 2);   
        tab->total_length += ft_putnbrBase(pointer_value, "0123456789abcdef");
    }
}