/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:15:07 by gcadiou           #+#    #+#             */
/*   Updated: 2017/03/21 14:21:24 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "headerls.h"

int				stock_arg(int argc, char **argv, struct s_lsopt *ls_opt)
{
		int		i;
		char	*buf;

		i = 0;
		while (i < argc)
		{
			if (argv[i][0] == '-')
			{
				ls_opt->l += ft_strchr(argv[i], 'l') ? 1 : 0;
				ls_opt->R += ft_strchr(argv[i], 'R') ? 1 : 0;
				ls_opt->a += ft_strchr(argv[i], 'a') ? 1 : 0;
				ls_opt->r += ft_strchr(argv[i], 'r') ? 1 : 0;
				ls_opt->t += ft_strchr(argv[i], 't') ? 1 : 0;
			}
			i++;
		}
		return (0);
}

int				stock_space(struct s_infos *infos, struct s_space *space)
{
	space->blocks = ft_intlen(infos->stats->st_blocks);
	space->nlink = ft_intlen(infos->stats->st_nlink);
	space->usr = ft_strlen(getpwuid(infos->stats->st_uid)->pw_name);
	space->grp = ft_strlen(getgrgid(infos->stats->st_gid)->gr_name);
	space->size = ft_intlen(infos->stats->st_size);
	while (infos->next != NULL)
	{
		infos = infos->next;
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

struct s_infos	*stock_infos(DIR *dir, struct s_infos *infos, char *name)
{
	int				first;
	char			*buf;
	struct dirent	*tmp;

	first = 1;
	while ((tmp = readdir(dir)))
	{
		if (first == 0)
		{
			infos->next = addinfo();
			infos = infos->next;
		}
		first = 0;
		infos->file = tmp;
		buf = ft_strjoin(name, infos->file->d_name);
		infos->stats = (struct stat*)malloc(sizeof(struct stat));
		stat(buf, infos->stats);
	}
	return (0);
}
