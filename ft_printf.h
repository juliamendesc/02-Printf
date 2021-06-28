#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct s_flags
{
	int		type;
	int		width;
	int		prec;
	int		minus;
	int		zero;
	int		dot;
	int		dash;
	int		star;
	int		total_length;
}			t_flags;

int	ft_printf(const char *format, ...);
int	ft_incoming(const char *format, va_list args);
int	ft_parse_flags(const char *format, int i, t_flags *tab, va_list args);
int	ft_check_flags(char c);
t_flags ft_init_tab(void);
int	ft_is_flag(char c);
int	ft_which_type(char c);
int	ft_flag_dot(const char *format, int i, t_flags *tab, va_list args);
t_flags	ft_flag_minus(t_flags tab);
t_flags	ft_flag_width(va_list args, t_flags tab);
int	ft_convert(char type, t_flags tab, va_list args);
int	ft_width_treat(int width, int slots, int includes_zero);
int	ft_putchat_returnint(char c);
int	ft_convert_char(int c, t_flags tab);
int	ft_putstr_len(char *str, size_t len);
int	ft_convert_string(char *str, t_flags tab);
int	ft_putint_len(char *str, t_flags tab);
int	ft_length(char *str, t_flags tab, int i);
int	ft_handle_int(char *str, t_flags *tab, int len);

#endif
