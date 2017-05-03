/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:08:36 by gcadiou           #+#    #+#             */
/*   Updated: 2017/04/26 10:59:09 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

void		disp_total(struct s_space *space)
{
	ft_putstr("total ");
	ft_putnbr(space->total);
	ft_putchar('\n');
}

void		disp_mode(struct stat *infos)
{
	ft_putchar(S_ISREG(infos->st_mode) ? '-' : '\0');
	ft_putchar(S_ISDIR(infos->st_mode) ? 'd' : '\0');
	ft_putchar(S_ISLNK(infos->st_mode) ? 'l' : '\0');
	ft_putchar(S_ISBLK(infos->st_mode) ? 'b' : '\0');
	ft_putchar(S_ISCHR(infos->st_mode) ? 'c' : '\0');
	ft_putchar(S_ISSOCK(infos->st_mode) ? 's' : '\0');
	ft_putchar(S_ISFIFO(infos->st_mode) ? 'p' : '\0');
	ft_putchar((infos->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((infos->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((infos->st_mode & S_IXUSR) ? ((infos->st_mode & S_ISUID) ? 's' :
			'x') : (infos->st_mode & S_ISUID) ? 'S' : '-');
	ft_putchar((infos->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((infos->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((infos->st_mode & S_IXGRP) ? ((infos->st_mode & S_ISGID) ? 's' :
			'x') : (infos->st_mode & S_ISGID) ? 'S' : '-');
	ft_putchar((infos->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((infos->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((infos->st_mode & S_IXOTH) ? 'x' : '-');
}

void		disp_divers(struct stat *stats, struct s_space *space)
{
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
}

void		disp_time(struct stat *stats, struct s_space *space,
			struct s_lsopt *ls_opt)
{
	int		sixmonths;

	sixmonths = ((365 / 2) * (3600 * 24));
	if (ls_opt->u > 0)
	{
		if (time(0) - sixmonths > stats->st_atime || stats->st_atime > time(0))
		{
			ft_putstr_size(ft_strcut(ctime(&(stats->st_atime)), 4, 11), 24);
			ft_strcut(ctime(&(stats->st_atime)), 19, 24);
		}
		else
			ft_putstr_size(ft_strcut(ctime(&(stats->st_atime)), 4, 16), 24);
	}
	else
	{
		if (time(0) - sixmonths > stats->st_mtime || stats->st_mtime > time(0))
		{
			ft_putstr_size(ft_strcut(ctime(&(stats->st_mtime)), 4, 11), 24);
			ft_strcut(ctime(&(stats->st_mtime)), 19, 24);
		}
		else
			ft_putstr_size(ft_strcut(ctime(&(stats->st_mtime)), 4, 16), 24);
	}
}
