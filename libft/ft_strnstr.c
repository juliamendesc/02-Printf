/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:42:44 by julcarva          #+#    #+#             */
/*   Updated: 2021/02/17 14:43:09 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*find == '\0')
		return ((char *)s);
	while (i < n && s[i] != '\0')
	{
		j = 0;
		while (i + j < n && s[i + j] == find[j] && find[j] != '\0')
			j++;
		if (find[j] == '\0')
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
