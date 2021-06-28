/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:30:02 by julcarva          #+#    #+#             */
/*   Updated: 2021/02/17 14:54:53 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*src;
	char	find;
	size_t	i;

	src = (char *)s;
	find = (char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == find)
		{
			return ((char *)src + i);
		}
		i++;
	}
	return (NULL);
}
