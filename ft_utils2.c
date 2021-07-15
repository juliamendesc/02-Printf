#include "ft_printf.h"

int	absolute_value(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	get_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = get_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
		result[0] = '-';
	else if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		--len;
		result[len] = absolute_value(n % 10) + '0';
		n = n / 10;
	}
	return (result);
}

char	*ft_utoa(unsigned int n)
{
	char			*str;
	int				size;
	unsigned int	x;

	x = n;
	size = 0;
	if (x < 0)
		x *= -1;
	while (x >= 10)
	{
		x /= 10;
		size++;
	}
	str = (char *)malloc(sizeof(str) * (size + 1));
	ft_free_and_null(str);
	str[size + 1] = '\0';
	while (size >= 0)
	{
		x = n % 10;
		str[size--] = '0' + x;
		n = n / 10;
	}
	return (str);
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
	ft_free_and_null(str);
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
