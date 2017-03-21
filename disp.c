/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:02:50 by gcadiou           #+#    #+#             */
/*   Updated: 2017/03/21 15:03:21 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

void		disp_divers(struct stat *stats, struct s_space *space)
{
	int		sixmonths;

	sixmonths = ((365 / 2) * (3600 * 24));
	ft_put_nb_c(' ', space->nlink - ft_intlen(stats->st_nlink));
	ft_putnbr(stats->st_nlink);
	ft_putchar(' ');
	ft_put_nb_c(' ', space->usr -
			ft_strlen(getpwuid(stats->st_uid)->pw_name));
	ft_putstr(getpwuid(stats->st_uid)->pw_name);
	ft_putstr("  ");
	ft_put_nb_c(' ', space->grp -
			ft_strlen(getgrgid(stats->st_gid)->gr_name));
	ft_putstr(getgrgid(stats->st_gid)->gr_name);
	ft_putchar(' ');
	ft_put_nb_c(' ', space->size - ft_intlen(stats->st_size));
	ft_putnbr(stats->st_size);
	ft_putstr("  ");
	if (time(0) - sixmonths > stats->st_mtime || stats->st_mtime > time(0))
	{
		ft_putstr_size(ft_strcut(ctime(&(stats->st_mtime)), 4, 11), 24);
		ft_strcut(ctime(&(stats->st_mtime)), 19, 24);
	}
	else
		ft_putstr_size(ft_strcut(ctime(&(stats->st_mtime)), 4, 16), 24);
}

void		disp_name(struct s_infos *infos)
{
	if (S_ISDIR(infos->stats->st_mode))
		COLOR(S_CYAN);
	else if (infos->stats->st_mode & S_IXUSR
			|| infos->stats->st_mode & S_IXGRP
			|| infos->stats->st_mode & S_IXOTH)
		COLOR(RED);
	else if (S_ISLNK(infos->stats->st_mode))
		COLOR(S_MAGENTA);
	ft_putstr(infos->file->d_name);
	COLOR(NONE);
}

void		disp_simple(struct s_infos *infos, struct s_space *space)
{
	disp_name(infos);
	ft_putchar('\n');
}

void		disp_all(struct s_infos *infos, struct s_space *space)
{
	while (infos->next != NULL)
	{
		/*		disp_block(infos->stats, space);
				ft_putchar(' ');
				disp_mode(infos->stats, space);
				ft_put_nb_c(' ', 2);*/
		disp_divers(infos->stats, space);
		ft_putchar(' ');
		disp_name(infos);
		ft_putchar('\n');
	}
}
