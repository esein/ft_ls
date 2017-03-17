/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:59:15 by gcadiou           #+#    #+#             */
/*   Updated: 2016/11/23 21:40:30 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lboucles(long nb, int fd)
{
	char	b;

	while (nb > 0)
	{
		b = (char)(nb % 10) + '0';
		nb = lboucles(nb / 10, fd);
		ft_putchar_fd(b, fd);
	}
	return (0);
}

void		ft_putnbr_fd(int nb, int fd)
{
	long	lnb;

	if (nb < 0)
	{
		lnb = nb;
		ft_putchar_fd('-', fd);
		lnb = lnb * -1;
		lboucles(lnb, fd);
	}
	else if (nb == 0)
		ft_putchar_fd('0', fd);
	else
		lboucles(nb, fd);
}
