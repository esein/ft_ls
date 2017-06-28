/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 18:15:40 by gcadiou           #+#    #+#             */
/*   Updated: 2017/06/28 18:52:59 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

void		disp_total(struct s_space *space)
{
	ft_putstr("total ");
	ft_putnbr(space->total);
	ft_putchar('\n');
}

void		disp_mode2(struct stat *infos)
{
	if (infos->st_mode & S_ISTXT)
		ft_putchar((infos->st_mode & S_IXOTH) ? 't' : 'T');
	else
		ft_putchar((infos->st_mode & S_IXOTH) ? 'x' : '-');
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
	if (infos->st_mode & S_IXUSR)
		ft_putchar((infos->st_mode & S_ISUID) ? 's' : 'x');
	else
		ft_putchar((infos->st_mode & S_ISUID) ? 'S' : '-');
	ft_putchar((infos->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((infos->st_mode & S_IWGRP) ? 'w' : '-');
	if (infos->st_mode & S_IXGRP)
		ft_putchar((infos->st_mode & S_ISGID) ? 's' : 'x');
	else
		ft_putchar((infos->st_mode & S_ISGID) ? 'S' : '-');
	ft_putchar((infos->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((infos->st_mode & S_IWOTH) ? 'w' : '-');
	disp_mode2(infos);
}

void		disp_divers(struct stat *stats, struct s_space *space)
{
	ft_put_nb_c(' ', space->nlink - ft_intlen(stats->st_nlink));
	ft_putnbr(stats->st_nlink);
	ft_putchar(' ');
	ft_putstr(getpwuid(stats->st_uid)->pw_name);
	ft_put_nb_c(' ', (space->usr -
			ft_strlen(getpwuid(stats->st_uid)->pw_name)) + 2);
	ft_putstr(getgrgid(stats->st_gid)->gr_name);
	ft_put_nb_c(' ', space->grp -
			ft_strlen(getgrgid(stats->st_gid)->gr_name));
	ft_putstr("  ");
	if (S_ISCHR(stats->st_mode) || S_ISBLK(stats->st_mode))
		disp_dev(stats, space);
	else
	{
		if (space->majeur == 0)
			ft_put_nb_c(' ', space->size - ft_intlen(stats->st_size));
		else
			ft_put_nb_c(' ', (space->majeur + 2 + space->mineur) - space->size);
		ft_putnbr(stats->st_size);
	}
}

void		disp_dev(struct stat *stats, struct s_space *space)
{
	ft_put_nb_c(' ', space->majeur - ft_intlen(major(stats->st_rdev)));
	ft_putnbr(major(stats->st_rdev));
	ft_putstr(", ");
	ft_put_nb_c(' ', space->mineur - ft_intlen(minor(stats->st_rdev)));
	ft_putnbr(minor(stats->st_rdev));
}
