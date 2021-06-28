/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:00:22 by julcarva          #+#    #+#             */
/*   Updated: 2021/02/24 18:48:51 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntwrd(char const *str, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && (str[i] != c))
			i++;
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	if (!(tab = (char **)ft_calloc(sizeof(char *), (ft_cntwrd(s, c)) + 1)))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[k] = ft_strndup(s + j, i - j);
			k++;
		}
	}
	return (tab);
}
