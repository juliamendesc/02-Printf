
#include "ft_printf.h"

int	ft_width_treat(int width, int slots, int includes_zero)
{
	int	count;
	int	diff;

	count = 0;
	diff = width - slots;
	while (diff > 0)
	{
		if (includes_zero)
			ft_putchar_fd('0', 1);
		ft_putchar_fd(' ', 1);
		diff--;
		count++;
	}
	return (count);
}