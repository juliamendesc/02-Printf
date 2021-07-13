#include "ft_printf.h"

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

void	ft_reverse_string(char *str, int begin, int end)
{
	char	c;

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
