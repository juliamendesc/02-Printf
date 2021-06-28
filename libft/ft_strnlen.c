/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:35:59 by julcarva          #+#    #+#             */
/*   Updated: 2021/02/17 15:01:01 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t len;

	len = 0;
	while (len < maxlen)
	{
		if (!*s)
			break ;
		len++;
		s++;
	}
	return (len);
}
