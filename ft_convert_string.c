
#include "ft_printf.h"

int	ft_putstr_len(char *str, size_t len)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (len-- && *str)
		count += ft_putchat_returnint(*(str++));
	return (count);
}

int	ft_convert_string(char *str, t_flags tab)
{
	int		count;
	int		len;

	count = 0;
	if (!str)
		str = "(null)"; //pq? pra dizer que nao existe nada?
	len = ft_strlen(str);
	if (tab.dot >= 0 && tab.dot < len)
		len = tab.dot;
	if (tab.minus)
		count += ft_putstr_len(str, len);
	count += ft_width_treat(tab.width, len, tab.zero);
	if (!tab.minus)
		count += ft_putstr_len(str, len);
	return (count);
}