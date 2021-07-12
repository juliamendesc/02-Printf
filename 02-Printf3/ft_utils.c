
#include "ft_printf.h"

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
	copy = malloc((unsigned int)len);
    if (!copy)
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

char	*ft_strjoinchr(char *s1, char s2)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	if (!s1 || !s2)
	{
		free(s1);
		return (NULL);
	}
	len = ft_strlen(s1);
	temp = malloc((len + 2) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = s2;
	i++;
	temp[i] = '\0';
	return (temp);
}

void    ft_reverse_string(char *str, int begin, int end)
{
    char c;

    if (begin >= end)
        return ;
    c = *(str + begin);
    *(str + begin) = *(str + end);
    *(str + end) = c;

    ft_reverse_string(str, ++begin, --end);
}

int	ft_putnbrBase(unsigned long n, char *base)
{
	unsigned int	baseLength;
	int				numLength;

	numLength = 1;
	baseLength = ft_strlen(base);
	if (n == 0)
	{
		write(1, "0", 1);
		return (numLength);
	}
	if (n >= baseLength)
	{
		numLength += ft_putnbrBase(n / baseLength, base);
		write(1, &base[n % baseLength], 1);
	}
	else if (n < baseLength)
		write(1, &base[n], 1);
	return (numLength);
}