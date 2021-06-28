/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:33:20 by julcarva          #+#    #+#             */
/*   Updated: 2021/02/24 18:34:56 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(long int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i *= -1;
	}
	while (i != 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			count;
	int			i;
	long int	nb;

	nb = n;
	count = ft_digit_count(nb);
	i = 0;
	if (nb < 0 || count == 0)
		count++;
	if (!(str = ft_calloc(sizeof(char), (count + 1))))
		return (0);
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
		i++;
	}
	while (count > i)
	{
		count--;
		str[count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
