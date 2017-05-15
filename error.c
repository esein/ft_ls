/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:40:57 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/15 19:09:42 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

static void	disp_usage()
{
	ft_puterror("usage: ls [-1RSaflrstu] [file ...]");
}

void		*open_error(char *name)
{
	if (errno == ENOTDIR)
	{
		ft_puterror(ft_str_endcut(name, 1));
		ft_putcharerror('\n');
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

void		arg_error(char arg)
{
	ft_puterror("ls: illegal option -- ");
	ft_putcharerror(arg);
	ft_putcharerror('\n');
	disp_usage();
	ft_putcharerror('\n');
	exit(0);
}
