/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:43:49 by gcadiou           #+#    #+#             */
/*   Updated: 2016/11/25 00:31:10 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strrev(char *s)
{
	size_t	size;
	size_t	size2;
	char	a;
	char	b;

	size = 0;
	size2 = 0;
	while (s[size] != '\0')
		size++;
	size--;
	while (size > size2)
	{
		a = s[size];
		b = s[size2];
		s[size] = b;
		s[size2] = a;
		size--;
		size2++;
	}
	return (s);
}

static size_t	nbchar(long nb)
{
	size_t	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static void		vivelanorme(char *s, int x, size_t i, long nb)
{
	while (nb > 0)
	{
		s[i] = (nb % 10) + 48;
		nb /= 10;
		i++;
	}
	if (x == -1)
		s[i] = '-';
	ft_strrev(s);
}

char			*ft_itoa(int n)
{
	int		x;
	size_t	i;
	char	*s;
	long	nb;

	nb = n;
	x = 0;
	i = 0;
	if (!(s = ft_strnew(nbchar(nb))))
		return (NULL);
	if (nb < 0)
	{
		x = -1;
		nb = -nb;
	}
	if (nb == 0)
		s[0] = '0';
	else
		vivelanorme(s, x, i, nb);
	return (s);
}
