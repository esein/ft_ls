/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 06:07:37 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/09 17:36:30 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

void			stock_space3(struct s_infos *infos, struct s_space *space)
{
	if (getpwuid(infos->stats->st_uid))
	{
		if (space->usr < ft_strlen(getpwuid(infos->stats->st_uid)->pw_name))
			space->usr = ft_strlen(getpwuid(infos->stats->st_uid)->pw_name);
	}
	else
	{
		if (space->usr < ft_intlen(infos->stats->st_uid))
			space->usr = ft_intlen(infos->stats->st_uid);
	}
	if (getgrgid(infos->stats->st_gid))
	{
		if (space->grp < ft_strlen(getgrgid(infos->stats->st_gid)->gr_name))
			space->grp = ft_strlen(getgrgid(infos->stats->st_gid)->gr_name);
	}
	else
	{
		if (space->grp < ft_intlen(infos->stats->st_gid))
			space->grp = ft_intlen(infos->stats->st_gid);
	}
}

void			stock_space2(struct s_infos *infos, struct s_space *space,
		struct s_lsopt *ls_opt)
{
	if (space->name < ft_strlen(infos->name))
		space->name = ft_strlen(infos->name);
	if (ls_opt->a > 0 || infos->name[0] != '.')
		space->total += infos->stats->st_blocks;
	if (S_ISCHR(MODE) || S_ISBLK(MODE))
	{
		if (space->majeur < ft_intlen(major(infos->stats->st_rdev)))
			space->majeur = ft_intlen(major(infos->stats->st_rdev));
		if (space->majeur < ft_intlen(minor(infos->stats->st_rdev)))
			space->mineur = ft_intlen(minor(infos->stats->st_rdev));
	}
	if (space->blocks < ft_intlen(infos->stats->st_blocks))
		space->blocks = ft_intlen(infos->stats->st_blocks);
	if (space->nlink < ft_intlen(infos->stats->st_nlink))
		space->nlink = ft_intlen(infos->stats->st_nlink);
	stock_space3(infos, space);
	if (space->size < ft_intlen(infos->stats->st_size))
		space->size = ft_intlen(infos->stats->st_size);
}

int				stock_space(struct s_infos *infos, struct s_space *space,
		struct s_lsopt *ls_opt)
{
	space->blocks = ft_intlen(infos->stats->st_blocks);
	space->nlink = ft_intlen(infos->stats->st_nlink);
	space->usr = (getpwuid(infos->stats->st_uid)) ?
		ft_strlen(getpwuid(infos->stats->st_uid)->pw_name) :
		ft_intlen(infos->stats->st_uid);
	space->grp = (getgrgid(infos->stats->st_gid)) ?
		ft_strlen(getgrgid(infos->stats->st_gid)->gr_name) :
		ft_intlen(infos->stats->st_uid);
	space->size = ft_intlen(infos->stats->st_size);
	space->total = infos->stats->st_blocks;
	space->name = ft_strlen(infos->name);
	if (S_ISCHR(MODE) || S_ISBLK(MODE))
	{
		space->majeur = ft_intlen(major(infos->stats->st_rdev));
		space->mineur = ft_intlen(minor(infos->stats->st_rdev));
	}
	else
	{
		space->majeur = 0;
		space->mineur = 0;
	}
	while ((infos = infos->next) != NULL)
		stock_space2(infos, space, ls_opt);
	return (0);
}
