/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:50:17 by gcadiou           #+#    #+#             */
/*   Updated: 2017/04/26 11:02:29 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "headerls.h"

int		firstname(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
			return (i);
		i++;
	}
	return (0);
}

int		ft_ls(char *name, struct s_lsopt *ls_opt)
{
	DIR				*dir;
	struct s_infos	*infos;
	struct s_infos	*actual;
	struct s_space	space;

	infos = addinfo();
	actual = infos;
	if (!(dir = opendir(name)))
		return(open_error(name));
	stock_infos(dir, infos, name);
	stock_space(infos, &space, ls_opt);
	check_tri(infos, ls_opt);
	if (ls_opt->l > 0 || ls_opt->s > 0)
		disp_total(&space);
	while (actual != NULL)
	{
		if (ls_opt->a == 0 && actual->name[0] == '.')
			actual = actual->next;
		else
		{
			if (ls_opt->l > 0)
				disp_all(actual, &space, ls_opt);
			else
				disp_simple(actual, &space, ls_opt);
			actual = actual->next;
		}
	}
	free(infos);
	closedir(dir);
	return (0);
}

int		ls_R(char *name, struct s_lsopt *ls_opt)
{
	DIR				*dir;
	struct dirent	*file;

	ft_ls(name, ls_opt);
	if (!(dir = opendir(name)))
		return (open_error(name));
	file = readdir(dir);
	while ((file = readdir(dir)))
	{
		if (file->d_name[0] != '.' || ls_opt->a == 1)
			if (file->d_type == 4 && (ft_strcmp(file->d_name, "."))
				&& (ft_strcmp(file->d_name, "..")))
			{
				ft_put_nb_c('\n', 1);
				ft_putendl(ft_strjoin(name, ft_strjoin(file->d_name, ":")));
				ls_R(ft_strjoin(name, ft_strjoin(file->d_name, "/")), ls_opt);
			}
	}
	closedir(dir);
	return (0);
}

int		main(int argc, char **argv)
{
	struct s_lsopt	ls_opt;
	char			*name;
	int				first;

	stock_arg(argc, argv, &ls_opt);
	first = firstname(argc, argv);
	if (first == 0)
	{
		name = ft_strdup("./");
		if (ls_opt.R == 1)
			ls_R(name, &ls_opt);
		else
			ft_ls(name, &ls_opt);
	}
	else
	{
		while (first < argc)
		{
			name = ft_strjoin(argv[first], "/");
			if (ls_opt.R == 1)
				ls_R(name, &ls_opt);
			else
				ft_ls(name, &ls_opt);
			first++;
		}
	}
	return (0);
}
