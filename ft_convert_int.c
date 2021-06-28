
#include "ft_printf.h"

int	ft_putint_len(char *str, t_flags tab)
{
	int	count;
	int	len;
	int l;

	count = 0;
	len = ft_strlen(str);
	l = len;
	if (!str)
		return (0);
	if (*(str) == '-')
	{
		len--;
		count += ft_putchat_returnint(*(str++));
	}
	if (tab.dot > len || tab.zero && (tab.width > len))
	{
		while (tab.dot-- > len || (tab.zero && (tab.width > l++)))
			count += ft_putchat_returnint('0');
	}
	while (len-- && *str)
		count += ft_putchat_returnint(*(str++));
	return (count);
}

int	ft_length(char *str, t_flags tab, int i) //pq isso?
{
	int	len;

	len = ft_strlen(str);
	if (i < 0)
		len--;
	if (tab.dot > len)
		len = tab.dot;
	if (i < 0)
		len++;
	return (len);
}

int	ft_handle_int(char *str, t_flags *tab, int len)
{
	int count;
	count = 0;
	if (tab->dot >= 0 && tab->zero)
	{
		tab->zero = 0;
		count += ft_width_treat(tab->width, len, tab->zero);
	}
	else if (tab->dot < 0 && (tab->zero && (tab->width > len)))
	{
		count += ft_putint_len(str, *tab);
		tab->minus = 1;
	}
	else
		count += ft_width_treat(tab->width, len, tab->zero);
	return (count);
}