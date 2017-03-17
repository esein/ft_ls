/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 13:16:52 by gcadiou           #+#    #+#             */
/*   Updated: 2017/02/12 19:57:37 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlentil(const char *s, char c, size_t i)
{
	size_t	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static int	calcnbwords(char const *s, char c)
{
	int		nbwords;
	size_t	i;

	i = 0;
	nbwords = 0;
	if (s[i] == c)
		nbwords--;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		nbwords++;
		while (s[i] == c && s[i])
			i++;
	}
	return (nbwords);
}

static int	vivelanorme(char const *s, char c, int numwords)
{
	int		is;
	int		it;

	is = 0;
	it = 0;
	while (it++ != numwords)
	{
		while (s[is] == c)
			is++;
		while (s[is] && s[is] != c)
			is++;
	}
	while (s[is] == c)
		is++;
	return (is);
}

static char	**filltab(char **tab, char const *s, char c, int numwords)
{
	int		it1;
	size_t	is;
	size_t	it2;

	it2 = 0;
	it1 = 0;
	is = vivelanorme(s, c, numwords);
	if (!(tab[numwords] =
				(char *)malloc(sizeof(char) * strlentil(s, c, is) + 1)))
		return (0);
	while (s[is] != c && s[is])
	{
		tab[numwords][it2] = s[is];
		is++;
		it2++;
	}
	tab[numwords][it2] = '\0';
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nbwords;
	int		numwords;

	if (!s)
		return (NULL);
	nbwords = calcnbwords(s, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (nbwords + 1))))
		return (NULL);
	numwords = 0;
	while (numwords < nbwords)
	{
		tab = filltab(tab, s, c, numwords);
		numwords++;
	}
	tab[numwords] = 0;
	return (tab);
}
