/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:31:42 by julcarva          #+#    #+#             */
/*   Updated: 2021/02/17 16:15:48 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*ptr;

	if (nelem == 0 || elsize == 0)
	{
		nelem = 1;
		elsize = 1;
	}
	ptr = malloc(nelem * elsize);
	if (ptr)
		ft_bzero(ptr, nelem * elsize);
	return (ptr);
}
