/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:02:50 by gcadiou           #+#    #+#             */
/*   Updated: 2017/06/28 17:16:49 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

void		disp_name2(struct s_infos *infos)
{
	if (S_ISLNK(MODE))
		COLOR(C_LNK);
	else if ((MODE & S_IFMT) == S_IFSOCK)
		COLOR(C_SOCK);
	else if ((MODE & S_IFMT) == S_IFIFO)
		COLOR(C_FIFO);
	else if (S_ISBLK(MODE))
		COLOR(C_BLK);
	else if (S_ISCHR(MODE))
		COLOR(C_CHR);
	else if (MODE & (S_IXUSR | S_IXGRP | S_IXOTH))
	{
		if (MODE & S_ISUID)
			COLOR(C_SUID);
		else if (MODE & S_ISGID)
			COLOR(C_SGID);
		else
			COLOR(C_EXEC);
	}
}

void		disp_name(struct s_infos *infos, struct s_lsopt *ls_opt)
{
	if (ls_opt->bg == 1)
	{
		if (S_ISDIR(MODE))
		{
			if (MODE & S_IWOTH)
			{
				if (MODE & S_ISTXT)
					COLOR(C_WSDIR);
				else
					COLOR(C_WDIR);
			}
			else
				COLOR(C_DIR);
		}
		else
			disp_name2(infos);
	}
	ft_putstr(infos->name);
	if (ls_opt->bg == 1)
		COLOR(NONE);
}

void		disp_simple(struct s_infos *infos, struct s_space *space,
						struct s_lsopt *ls_opt)
{
	if (ls_opt->s > 0)
	{
		disp_block(infos->stats, space);
		ft_putchar(' ');
	}
	disp_name(infos, ls_opt);
	ft_putchar('\n');
}

void		disp_l(struct s_infos *infos, struct s_space *space,
					struct s_lsopt *ls_opt)
{
	if (ls_opt->s > 0)
		disp_block(infos->stats, space);
	disp_mode(infos->stats);
	ft_put_nb_c(' ', 2);
	disp_divers(infos->stats, space);
	ft_putstr("  ");
	disp_time(infos->stats, ls_opt);
	ft_putchar(' ');
	disp_name(infos, ls_opt);
	if (S_ISLNK(infos->stats->st_mode))
	{
		if (ls_opt->bg == 1)
			COLOR(NONE);
		ft_putstr(" -> ");
		ft_putstr(infos->lnk_name);
	}
	ft_putchar('\n');
}

void		disp_list(struct s_infos *infos, struct s_space *space,
						struct s_lsopt *ls_opt)
{
	while (infos != NULL)
	{
		if (ls_opt->l > 0)
			disp_l(infos, space, ls_opt);
		else
			disp_simple(infos, space, ls_opt);
		infos = infos->next;
	}
}
