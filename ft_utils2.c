#include "ft_printf.h"

int	ft_intlen(int digit)
{
	int	len;

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

char	*ft_itoa(int digit)
{
	char	*res;
	int		itoa_len;

	itoa_len = ft_intlen(digit);
	res = (char *)malloc(sizeof(char) * (itoa_len + 2));
	if (!res)
		return (NULL);
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

int	ft_uintlen(unsigned int digit)
{
	int	len;

	len = 0;
	while (digit != 0)
	{
		digit = digit / 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(int digit)
{
	char	*res;
	int		utoa_len;

	utoa_len = ft_uintlen(digit);
	res = (char *)malloc(sizeof(char) * (utoa_len + 1));
	if (!res)
		return (NULL);
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
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
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
