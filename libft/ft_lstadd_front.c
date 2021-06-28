/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:30:49 by julcarva          #+#    #+#             */
/*   Updated: 2021/06/08 12:44:58 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

 int		main(void)
{
	char	str[] = "lorem ipsum dolor sit";
	char	str2[] = "abcde";

	t_list	*elem;
	t_list	*elem2;

	elem = ft_lstnew((void *)str);
	elem2 = ft_lstnew((void *)str2);
	printf("\n%s\n", elem->content);
	ft_lstadd_front(&elem, elem2);
	printf("\n%s\n", elem->content);
	return (0);
}