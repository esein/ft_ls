/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:50:17 by gcadiou           #+#    #+#             */
/*   Updated: 2017/03/17 09:44:20 by gcadiou          ###   ########.fr       */
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

int		ft_ls(char *name, struct s_lsopt ls_opt)
{
	DIR				*dir;
	struct s_infos	*infos;
	struct s_infos	*actual;

	infos = addinfo();
	actual = infos;
	dir = opendir(name);
	stock_infos(dir, infos, name);
	while (actual->next != NULL)
	{
		ft_putstr(actual->file->d_name);
		actual = actual->next;
	}
	return (0);
}

int		ls_R(char *name, struct s_lsopt ls_opt)
{
	return (0);
}

int		main(int argc, char **argv)
{
	struct s_lsopt	ls_opt;
	char			*name;
	int				first;

	name = 0;
	if (argc == 1)
		name = ft_strdup("./");
	else
	{
		stock_arg(argc, argv, &ls_opt);
		first = firstname(argc, argv);
		while (first < argc - 1)
		{
			name = ft_strjoin(argv[first], "/");
			if (ls_opt.R == 1)
				ls_R(name, ls_opt);
			else
				ft_ls(name, ls_opt);
			first++;
		}
	}
	return (0);
}
