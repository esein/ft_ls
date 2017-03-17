/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 05:48:19 by gcadiou           #+#    #+#             */
/*   Updated: 2016/12/01 07:00:55 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_mal_double_tab(char **tab, size_t l, size_t i)
{
	size_t	count;

	count = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * l)))
		return (NULL);
	while (count < l)
	{
		if (!(tab[count] = (char *)malloc(sizeof(char) * i)))
			return (NULL);
		count++;
	}
	return (tab);
}
