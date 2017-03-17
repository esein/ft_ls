/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 23:01:15 by gcadiou           #+#    #+#             */
/*   Updated: 2016/11/24 06:06:50 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int count;
	int count2;
	int a;

	count = 0;
	if (!to_find[0])
		return ((char *)str);
	while (str[count] != '\0')
	{
		if (str[count] == to_find[0])
		{
			count2 = 0;
			a = count;
			while (str[count] == to_find[count2])
			{
				count++;
				count2++;
				if (to_find[count2] == '\0')
					return ((char *)str + count - count2);
			}
			count = a;
		}
		count++;
	}
	return (0);
}
