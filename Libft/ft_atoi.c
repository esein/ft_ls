/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 13:45:41 by gcadiou           #+#    #+#             */
/*   Updated: 2016/11/25 00:23:39 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	boucles(const char *str, int compteur, long nbr)
{
	int		negative;

	negative = 1;
	while (str[compteur] == 32 || str[compteur] == '\n' || str[compteur] == '\f'
	|| str[compteur] == '\v' || str[compteur] == '\t' || str[compteur] == '\r')
	{
		compteur++;
	}
	if (str[compteur] == 43)
		compteur++;
	else if (str[compteur] == 45)
	{
		negative = -1;
		compteur++;
	}
	while (str[compteur] < 58 && str[compteur] > 47)
	{
		nbr *= 10;
		nbr += (str[compteur] - 48);
		compteur++;
	}
	if (negative == -1)
		nbr *= negative;
	return (nbr);
}

int			ft_atoi(const char *str)
{
	int		compteur;
	long	nbr;

	compteur = 0;
	nbr = 0;
	nbr = boucles(str, compteur, nbr);
	return (nbr);
}
