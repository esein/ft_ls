/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:50:17 by gcadiou           #+#    #+#             */
/*   Updated: 2017/03/21 16:40:46 by gcadiou          ###   ########.fr       */
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
		open_error();
	stock_infos(dir, infos, name);
	stock_space(infos, &space);
	while (actual != NULL)
	{
		if (ls_opt->l == 1)
			disp_all(actual, &space);
		else
			disp_simple(actual, &space);
		actual = actual->next;
	}
	return (0);
}

int		ls_R(char *name, struct s_lsopt *ls_opt)
{
	return (0);
}

int		main(int argc, char **argv)
{
	struct s_lsopt	ls_opt;
	char			*name;
	int				first;

	if (argc == 1)
	{
		name = ft_strdup("./");
		if (ls_opt.R == 1)
			ls_R(name, &ls_opt);
		else
			ft_ls(name, &ls_opt);
	}
	else
	{
		stock_arg(argc, argv, &ls_opt);
		first = firstname(argc, argv);
		ft_putnbr(first);
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
