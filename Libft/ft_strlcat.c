/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 01:00:18 by gcadiou           #+#    #+#             */
/*   Updated: 2016/11/24 07:27:43 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i_d;
	size_t	i_s;
	size_t	lendst;

	i_s = 0;
	lendst = ft_strlen(dst);
	i_d = lendst;
	if (lendst < size)
	{
		while (i_d < size - 1 && src[i_s])
		{
			dst[i_d] = src[i_s];
			i_d++;
			i_s++;
		}
		dst[i_d] = '\0';
		return (ft_strlen(src) + lendst);
	}
	else
		return (ft_strlen(src) + size);
}
