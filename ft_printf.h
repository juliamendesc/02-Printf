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

int	ft_printf(const char *, ...);

#endif
