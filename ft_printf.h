#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_tab
{
	va_list	*args;
	char	*format;
	int		index;
	int		total_length;
}				t_tab;

int		ft_putchar(char c);
int		ft_putstr(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);
int		absolute_value(int nbr);
int		get_len(int nbr);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char	*ft_strjoinchr(char *s1, char s2);
void	ft_reverse_string(char *str, int begin, int end);
int		ft_putnbrBase(unsigned long n, char *base);
void	ft_putnbr(int nb);
void	ft_convert_char(t_tab *tab);
void	ft_convert_string(t_tab *tab);
void	ft_convert_number(t_tab *tab);
void	ft_convert_unsigned_number(t_tab *tab);
void	ft_convert_hexadecimal_upper(t_tab *tab);
void	ft_convert_hexadecimal_lower(t_tab *tab);
void	ft_convert_pointer(t_tab *tab);
void	init_struct(t_tab *tab, char *format, va_list *args);
void	ft_check_type(t_tab *tab);
void	ft_free_and_null(char *ptr);
int		ft_printf(const char *format, ...);

#endif