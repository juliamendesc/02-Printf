/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:41:04 by julcarva          #+#    #+#             */
/*   Updated: 2021/02/24 18:41:06 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char *copy;

	if (!(copy = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_strncpy(copy, str, n);
	copy[n] = '\0';
	return (copy);
}
