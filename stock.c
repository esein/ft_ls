/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:15:07 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/08 01:47:10 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "headerls.h"

int				stock_arg(int argc, char **argv, struct s_lsopt *ls_opt)
{
		int		i;
		char	*buf;

		i = 1;
		init_arg(ls_opt);
		while (i < argc)
		{
			if (argv[i][0] == '-')
			{
				ls_opt->l += ft_strchr(argv[i], 'l') ? 1 : 0;
				ls_opt->R += ft_strchr(argv[i], 'R') ? 1 : 0;
				ls_opt->a += ft_strchr(argv[i], 'a') ? 1 : 0;
				ls_opt->r += ft_strchr(argv[i], 'r') ? 1 : 0;
				ls_opt->t += ft_strchr(argv[i], 't') ? 1 : 0;
				ls_opt->u += ft_strchr(argv[i], 'u') ? 1 : 0;
				ls_opt->s += ft_strchr(argv[i], 's') ? 1 : 0;
				ls_opt->S += ft_strchr(argv[i], 'S') ? 1 : 0;
				ls_opt->f += ft_strchr(argv[i], 'f') ? 1 : 0;
			}
			else
				return (0);
			i++;
		}
		return (1);
}

int				stock_space(struct s_infos *infos, struct s_space *space,
				struct s_lsopt *ls_opt)
{
	space->blocks = ft_intlen(infos->stats->st_blocks);
	space->nlink = ft_intlen(infos->stats->st_nlink);
	space->usr = ft_strlen(getpwuid(infos->stats->st_uid)->pw_name);
	space->grp = ft_strlen(getgrgid(infos->stats->st_gid)->gr_name);
	space->size = ft_intlen(infos->stats->st_size);
	space->total = infos->stats->st_blocks;
	while (infos->next != NULL)
	{
		infos = infos->next;
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
		infos->name = ft_strdup(tmp->d_name);
		buf = ft_strjoin(name, infos->name);
		check_malloc(infos->stats = (struct stat*)malloc(sizeof(struct stat)),
				"ls: stocks_infos");
		if (tmp->d_type == DT_LNK)
		{
			check_malloc(infos->lnk_name = (char *)malloc(sizeof(char) * 250),
					"ls: stock_infos");
			infos->lnk_name[0] = 'a';
			infos->lnk_name[1] = '\0';
		}
		if (!(lstat(buf, infos->stats)))
			open_error(name);
	}
	return (0);
}
