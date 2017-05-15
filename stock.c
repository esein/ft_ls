/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:15:07 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/15 16:56:15 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "headerls.h"

int				stock_space(struct s_infos *infos, struct s_space *space,
							struct s_lsopt *ls_opt)
{
	space->blocks = ft_intlen(infos->stats->st_blocks);
	space->nlink = ft_intlen(infos->stats->st_nlink);
	space->usr = ft_strlen(getpwuid(infos->stats->st_uid)->pw_name);
	space->grp = ft_strlen(getgrgid(infos->stats->st_gid)->gr_name);
	space->size = ft_intlen(infos->stats->st_size);
	space->total = infos->stats->st_blocks;
	space->name = ft_strlen(infos->name);
	while ((infos = infos->next) != NULL)
	{
		if (space->name < ft_strlen(infos->name))
			space->name = ft_strlen(infos->name);
		if (ls_opt->a > 0 || infos->name[0] != '.')
			space->total += infos->stats->st_blocks;
		if (space->blocks < ft_intlen(infos->stats->st_blocks))
			space->blocks = ft_intlen(infos->stats->st_blocks);
		if (space->nlink < ft_intlen(infos->stats->st_nlink))
			space->nlink = ft_intlen(infos->stats->st_nlink);
		if (space->usr < ft_strlen(getpwuid(infos->stats->st_uid)->pw_name))
			space->usr = ft_strlen(getpwuid(infos->stats->st_uid)->pw_name);
		if (space->grp < ft_strlen(getgrgid(infos->stats->st_gid)->gr_name))
			space->grp = ft_strlen(getgrgid(infos->stats->st_gid)->gr_name);
		if (space->size < ft_intlen(infos->stats->st_size))
			space->size = ft_intlen(infos->stats->st_size);
	}
	return (0);
}

void			stock_index(struct s_infos *infos, struct s_lsopt *ls_opt,
							struct s_space *space)
{
	int		i;

	i = 1;
	while (infos != NULL)
	{
		if (infos->name[0] != '.' || ls_opt->a != 0)
		{
			infos->index = i;
			i++;
		}
		infos = infos->next;
	}
	space->nb_files = i - 1;
}

void			stock_lnk_name(struct s_infos *infos, char *path)
{
	int		lnk_len;

	check_malloc(infos->lnk_name =
			(char *)malloc(sizeof(char) * 1024),
			"ls: stock_infos(2)");
	if ((lnk_len = readlink(path, infos->lnk_name, sizeof(char) * 1024)) < 0)
		open_error(path);
	infos->lnk_name[lnk_len] = '\0';
}


struct s_infos	*stock_infos(DIR *dir, struct s_infos *infos, char *name,
							struct s_lsopt *ls_opt)
{
	int				notfirst;
	char			*buf;
	struct dirent	*tmp;

	while ((tmp = readdir(dir)))
	{
		if (ls_opt->a > 0 || tmp->d_name[0] != '.')
		{
			if (notfirst == 1)
			{
				infos->next = addinfo();
				infos = infos->next;
			}
			notfirst = 1;
			infos->name = ft_strdup(tmp->d_name);
			buf = ft_strjoin(name, infos->name);
			check_malloc((infos->stats = (struct stat*)malloc(
							sizeof(struct stat))), "ls: stocks_infos(1)");
			if (tmp->d_type == DT_LNK)
				stock_lnk_name(infos, buf);
			if ((lstat(buf, infos->stats)) < 0)
				open_error(name);
		}
	}
	return (0);
}
