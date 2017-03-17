/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_endcut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 08:29:32 by gcadiou           #+#    #+#             */
/*   Updated: 2017/02/22 08:36:59 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_endcut(char *s, int size)
{
	int		i;
	char	*new;

	i = ft_strlen(s) - size;
	new = ft_strnew(i);
	new = ft_strncpy(new, s, i);
	new[i] = '\0';
	return (new);
}
