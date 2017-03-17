/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 20:30:41 by gcadiou           #+#    #+#             */
/*   Updated: 2017/02/12 20:18:12 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	is;
	size_t	in;

	is = -1;
	in = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(new = malloc(sizeof(char) * ((ft_strlen(s1)) + (ft_strlen(s2)) + 1))))
		return (0);
	while (++is < (size_t)ft_strlen(s1))
	{
		new[in] = s1[is];
		in++;
	}
	is = -1;
	while (++is < (size_t)ft_strlen(s2))
	{
		new[in] = s2[is];
		in++;
	}
	new[in] = '\0';
	return (new);
}
