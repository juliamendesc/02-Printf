
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


typedef struct  s_tab
{
    va_list *args;
    char    *format;
    int     index;
    int     total_length;
}               t_tab;


/************** UTILS ********************/

int		ft_putchar(char c)
{
	write(1, &c, 1);
    return (1);
}

int     ft_putstr(char *str)
{
    int count;

    count = 0;
	if (!str)
		return 0;
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
        count++;
	}
    return (count);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (!dest && !src && n > 0)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int	ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(str) + 1;
	if (!(copy = malloc((unsigned int)len)))
		return (NULL);
	ft_memcpy(copy, str, len);
	return (copy);
}

int     ft_intlen(int digit)
{
	int len;

	len = 0;

	if (digit < 0)
		len++;
	while (digit != 0)
	{
		digit = digit / 10;
		len++;
	}
	return (len);
}

char    *ft_itoa(int digit)
{
    char    *res;
    int     itoa_len;

    itoa_len = ft_intlen(digit);

    res = (char *)malloc(sizeof(char) * (itoa_len + 2));
    if (!res)
        return NULL;
    res[itoa_len] = '\0';
    if (digit < 0)
        res[0] = '-';
    else if (digit == 0)
        res[0] = '0';
    if (digit < 0)
        digit *= -1;
    while (digit != 0)
    {
        itoa_len--;
        res[itoa_len] = digit % 10 + '0';
        digit = digit / 10;
    }
    return (res);
}

int     ft_uintlen(unsigned int digit)
{
    int len;

    len = 0;
    while (digit != 0)
    {
        digit = digit / 10;
        len++;
    }
    return (len);
}

char    *ft_utoa(int digit)
{
    char    *res;
    int     utoa_len;

    utoa_len = ft_uintlen(digit);
    res = (char *)malloc(sizeof(char) * (utoa_len + 1));
    if (!res)
        return NULL;
    res[utoa_len] = '\0';
    if (digit == 0)
        res[0] = '0';
    while (digit != 0)
    {
        utoa_len--;
        res[utoa_len] = digit % 10 + '0';
        digit = digit / 10;
    }
    return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	if (!(str = (char *)malloc(sizeof(char) *
			(ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void ft_convert_pointer_to_hex(int pointer_value, char * pointer, t_tab *tab)
{
    int value;
    int remainder;
    int hexa;
    char *temp;

    value = pointer_value;
    if (value >= 0 && value < 10)
    {
        temp = ft_itoa(value);
        pointer = ft_strjoin(pointer, temp);
        free (temp);
    }
    remainder = value % 16;
    while (value >= 10)
    {
        if (remainder >= 10)
        {
            hexa = 
        }
    }
}

/*******************************************************/

/*********************CONVERSIONS***********************/

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

void    ft_convert_pointer(t_tab *tab)
{
    char *pointer;
    int   pointer_value; //may need to change to long

    pointer = NULL;
    pointer_value = va_arg(*tab->args, int);
    if (pointer_value == '\0')
    {
        pointer = ft_strdup("0x0");
        tab->total_length += ft_strlen(pointer);
        write (1, &pointer, ft_strlen(pointer));
    }
    else if (pointer_value != '\0')
    {
        pointer = ft_strdup("0x");
        pointer = ft_convert_pointer_to_hex(pointer_value, pointer, tab); //conversion to hexadecimal
        tab->total_length += ft_strlen(pointer);
    }
    free(pointer);
}

/********************************************************/


/* typedef struct  s_tab
{
    va_list *args;
    char    *format;
    int     index;
    int     total_length;
}               t_tab; */

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
    if (tab->format[tab->index] == 's')
        ft_convert_string(tab); 
    if (tab->format[tab->index] == 'c')
        ft_convert_char(tab);
    if (tab->format[tab->index] == 'd' || tab->format[tab->index] == 'i')
        ft_convert_number(tab);
    /* if (tab->format[tab->index] == 'p')
        ft_convert_pointer(tab); */
    if (tab->format[tab->index] == 'u')
        ft_convert_unsigned_number(tab);
    /*if (tab->format[tab->index] == 'x' || tab->format[tab->index] == 'X')
        ft_convert_hexadecimal(tab); */
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

int     main()
{
    int a;
    int b;
    int *c = &a;

    a = ft_printf("%s %c %d %% %u %p\n", "ola", 'l', 123, 651442, c);
    b = printf("%s %c %d %% %u %p\n", "ola", 'l', 123, 651442, c);
    
    ft_printf("%d\n", a);
    printf("%d\n", b);
}


