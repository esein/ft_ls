/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:15:07 by gcadiou           #+#    #+#             */
/*   Updated: 2017/03/17 09:35:08 by gcadiou          ###   ########.fr       */
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
		stat(buf, infos->stats);
	}
	return (0);
}
