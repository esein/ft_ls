/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:40:57 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/05 21:15:42 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

int		open_error(char *name)
{
	if (errno == ENOTDIR)
	{
		ft_putstr(ft_str_endcut(name, 1));
		ft_putchar('\n');
		return (0);
	}
	perror("");
	return (0);
}

void	malloc_error()
{
	perror("");
	exit(0);
}
