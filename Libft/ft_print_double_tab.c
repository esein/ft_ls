/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 05:19:12 by gcadiou           #+#    #+#             */
/*   Updated: 2016/12/02 00:37:26 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_double_tab(char **tab, size_t l, size_t i)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	while (i1 < l)
	{
		i2 = 0;
		while (i2 < i)
		{
			ft_putchar(tab[i1][i2]);
			i2++;
		}
		ft_putchar('\n');
		i1++;
	}
}
