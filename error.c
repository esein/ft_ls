/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:40:57 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/10 03:11:09 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

void		*open_error(char *name)
{
	if (errno == ENOTDIR)
	{
		ft_putstr(ft_str_endcut(name, 1));
		ft_putchar('\n');
		return (0);
	}
	name = ft_str_endcut(name, 1);
	if (ft_strrchr(name, (int)'/') == 0)
		perror(ft_strjoin("ls: ", name));
	else
		perror(ft_strjoin("ls: ",
				&(ft_strrchr(name, (int)'/'))[1]));
	return (NULL);
}
