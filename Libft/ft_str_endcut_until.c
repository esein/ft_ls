/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_endcut_until.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 07:26:34 by gcadiou           #+#    #+#             */
/*   Updated: 2017/02/22 08:41:08 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_endcut_until(char *s, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (s[i] != c)
	{
		i--;
		if (i < 0)
			return (s);
	}
	if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	new = ft_strncpy(new, s, i + 1);
	new[i + 1] = '\0';
	return (new);
}
