/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:01:12 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/22 19:01:58 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

void		disp_time(struct stat *stats, struct s_lsopt *ls_opt)
{
	int		sixmonths;

	sixmonths = ((365 / 2) * (3600 * 24));
	if (ls_opt->u > 0)
	{
		if (time(0) - sixmonths > stats->st_atime || stats->st_atime > time(0))
		{
			ft_putstr_size(ft_strcut(ctime(&(stats->st_atime)), 4, 11), 24);
			ft_putstr(ft_strcut(ctime(&(stats->st_atime)), 19, 24));
		}
		else
			ft_putstr_size(ft_strcut(ctime(&(stats->st_atime)), 4, 16), 24);
	}
	else
	{
		if (time(0) - sixmonths > stats->st_mtime || stats->st_mtime > time(0))
		{
			ft_putstr_size(ft_strcut(ctime(&(stats->st_mtime)), 4, 11), 24);
			ft_putstr(ft_strcut(ctime(&(stats->st_mtime)), 19, 24));
		}
		else
			ft_putstr_size(ft_strcut(ctime(&(stats->st_mtime)), 4, 16), 24);
	}
}
