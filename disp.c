/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:02:50 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/09 08:02:33 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

void		disp_block(struct stat *stats, struct s_space *space)
{
	ft_put_nb_c(' ', space->blocks - ft_intlen(stats->st_blocks));
	ft_putnbr(stats->st_blocks);
}

void		disp_name(struct s_infos *infos)
{
	if (S_ISDIR(infos->stats->st_mode))
		COLOR(S_CYAN);
	else if (S_ISREG(infos->stats->st_mode) && (infos->stats->st_mode & S_IXUSR
			|| infos->stats->st_mode & S_IXGRP
			|| infos->stats->st_mode & S_IXOTH))
		COLOR(RED);
	else if (S_ISLNK(infos->stats->st_mode))
		COLOR(MAGENTA);
	ft_putstr(infos->name);
	COLOR(NONE);
}

void		disp_lnk_name(struct s_infos *infos)
{
	COLOR(MAGENTA);
	ft_putstr(infos->name);
	COLOR(NONE);
	ft_putstr(" -> ");
	ft_putstr(infos->lnk_name);
}

void		disp_simple(struct s_infos *infos, struct s_space *space,
						struct s_lsopt *ls_opt)
{
	if (ls_opt->s > 0)
	{
		disp_block(infos->stats, space);
		ft_putchar(' ');
	}
	disp_name(infos);
	ft_putchar('\n');
}

void		disp_all(struct s_infos *infos, struct s_space *space,
					struct s_lsopt *ls_opt)
{
		if (ls_opt->s > 0)
		{
			disp_block(infos->stats, space);
			ft_putchar(' ');
		}
		disp_mode(infos->stats);
		ft_put_nb_c(' ', 2);
		disp_divers(infos->stats, space);
		ft_putstr("  ");
		disp_time(infos->stats, space, ls_opt);
		ft_putchar(' ');
		if (S_ISLNK(infos->stats->st_mode))
			disp_lnk_name(infos);
		else
			disp_name(infos);
		ft_putchar('\n');
}
