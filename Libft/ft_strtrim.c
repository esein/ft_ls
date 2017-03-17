/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 20:42:42 by gcadiou           #+#    #+#             */
/*   Updated: 2016/11/25 08:36:11 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calcul_spaces(char const *s)
{
	int		spaces;
	size_t	i_s;

	i_s = 0;
	spaces = 0;
	while (s[i_s] && ISSPACE(s, i_s))
	{
		spaces++;
		i_s++;
	}
	if (s[i_s])
	{
		while (s[i_s])
			i_s++;
		i_s--;
		while (ISSPACE(s, i_s))
		{
			spaces++;
			i_s--;
		}
	}
	return (spaces);
}

char		*ft_strtrim(char const *s)
{
	size_t	i_s;
	size_t	i_n;
	size_t	lennew;
	char	*new;

	i_n = 0;
	i_s = 0;
	if (!s)
		return (NULL);
	lennew = ft_strlen(s) - calcul_spaces(s);
	i_s = 0;
	if (!(new = malloc(sizeof(char) * (lennew + 1))))
		return (0);
	while (s[i_s] && ISSPACE(s, i_s))
		i_s++;
	while (i_n < lennew)
	{
		new[i_n] = s[i_s];
		i_s++;
		i_n++;
	}
	new[i_n] = '\0';
	return (new);
}
