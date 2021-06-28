/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:38:07 by julcarva          #+#    #+#             */
/*   Updated: 2021/02/24 18:28:52 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!(lst))
		return (NULL);
	tmp = lst;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		return (tmp);
	}
	else
		return (NULL);
}
