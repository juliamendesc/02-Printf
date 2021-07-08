#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef	struct s_flags
{
	int		dot;
	int		minus;
	int		hash;
	int		width;
	int		zero;
	int		plus;
	int		total_length;
}			t_flags;

int	ft_printf(const char *format, ...);

#endif
