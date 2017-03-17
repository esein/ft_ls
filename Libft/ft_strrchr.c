/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 00:44:12 by gcadiou           #+#    #+#             */
/*   Updated: 2016/11/25 00:45:18 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		tmp;

	tmp = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			tmp = (int)i;
		i++;
	}
	if (tmp != -1)
		return ((char *)&s[tmp]);
	else if (s[i] == c)
		return ((char *)&s[i]);
	else
		return (0);
}
