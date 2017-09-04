/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:50:17 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/04 18:41:32 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

int				firstname(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
			return (i);
		else if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if ((i + 1) < argc)
				return (i + 1);
			else
				return (0);
		}
		i++;
	}
	if (argc > 1)
		if (argv[1][0] == '-' && argv[1][1] == '\0')
			return (1);
	return (0);
}

struct s_infos	*ft_ls(char *name, struct s_lsopt *ls_opt)
{
	DIR				*dir;
	struct s_infos	*infos;
	struct s_infos	*actual;
	struct s_space	space;

	infos = addinfo();
	actual = infos;
	if (!(dir = opendir(name)))
		return (open_error(name));
	stock_infos(dir, infos, name, ls_opt);
	if (infos->stats == NULL)
		return (NULL);
	stock_space(infos, &space, ls_opt);
	check_tri(infos, ls_opt);
	stock_index(infos, ls_opt, &space);
	if (ls_opt->l > 0 || ls_opt->s > 0)
		disp_total(&space);
	if (ls_opt->l > 0 || ls_opt->one > 0)
		disp_list(infos, &space, ls_opt);
	else
		disp_columns(infos, &space, ls_opt);
	closedir(dir);
	return (infos);
}

void			call_ls(char *name, struct s_lsopt *ls_opt)
{
	if (ls_opt->br == 1)
		ls_br(name, ls_opt);
	else
		ft_ls(name, ls_opt);
}

int				files_arg(int argc, char **argv, int first,
							struct s_lsopt *ls_opt)
{
	int		i;
	DIR		*dir;

	i = first;
	while (i < argc)
	{
		if (!(dir = opendir(ft_strjoin(argv[i], "/"))))
			open_error(ft_strjoin(argv[i], "/"));
		else
		{
			if ((argc - first) > 1)
			{
				ft_putstr(argv[i]);
				ft_putstr(":\n");
			}
			if (argv[i][0] == '/' && (argv[i][1] == 0))
				call_ls(argv[i], ls_opt);
			else
				call_ls(ft_strjoin(argv[i], "/"), ls_opt);
		}
		if ((argc - i) > 1)
			ft_putchar('\n');
		i++;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	struct s_lsopt	ls_opt;
	char			*name;
	int				first;
	struct s_infos	*infos;

	infos = 0;
	name = 0;
	stock_arg(argc, argv, &ls_opt);
	first = firstname(argc, argv);
	if (first == 0)
	{
		name = ft_strdup("./");
		if (ls_opt.br == 1)
			ls_br(name, &ls_opt);
		else
			infos = ft_ls(name, &ls_opt);
	}
	else
		files_arg(argc, argv, first, &ls_opt);
	if (name)
		free(name);
	if (infos)
		free(infos);
	return (0);
}
