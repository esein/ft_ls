/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:53:30 by gcadiou           #+#    #+#             */
/*   Updated: 2017/02/12 17:03:36 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *s, int start, int end)
{
	char	buf[ft_strlen(s) + 1];
	int		i;
	int		i2;

	i = 0;
	i2 = start;
	ft_strcpy(buf, s);
	while (s[i2] && i2 < end)
	{
		s[i] = buf[i2];
		i++;
		i2++;
	}
	s[i] = '\0';
	return (s);
}
