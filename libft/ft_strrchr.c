/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:36:27 by julcarva          #+#    #+#             */
/*   Updated: 2021/02/17 14:47:36 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;

	a = c;
	i = ft_strlen(s);
	if (a == 0)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
