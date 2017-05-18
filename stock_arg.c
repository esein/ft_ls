/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:44:27 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/18 16:33:56 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

static int			stock_arg3(struct s_lsopt *ls_opt, char c)
{
	if (c == 'R')
		ls_opt->R = 1;
	else if (c == 'a')
		ls_opt->a = 1;
	else if (c == 'r')
		ls_opt->r = 1;
	else if (c == 't')
		ls_opt->t = 1;
	else if (c == 'u')
		ls_opt->u = 1;
	else if (c == 's')
		ls_opt->s = 1;
	else if (c == 'S')
		ls_opt->S = 1;
	else if (c == 'f')
		ls_opt->f = 1;
	else if (c == 'G')
		ls_opt->G = 1;
	else
		return (0);
	return (1);
}

static int			stock_arg2(struct s_lsopt *ls_opt, char c)
{
		if (c == '1')
		{
			ls_opt->one = 1;
			ls_opt->l = 0;
		}
		else if (c == 'l')
		{
			ls_opt->l = 1;
			ls_opt->one = 0;
		}
		else if (stock_arg3(ls_opt, c) == 0)
			return (0);
		return (1);
}

int				stock_arg(int argc, char **argv, struct s_lsopt *ls_opt)
{
		int		i;
		int		j;

		i = 1;
		init_arg(ls_opt);
		while (i < argc)
		{
			j = 1;
			if (argv[i][0] == '-' && argv[i][1])
			{
				while (argv[i][j])
				{
					if (stock_arg2(ls_opt, argv[i][j]) == 0)
						arg_error(argv[i][j]);
					j++;
				}
			}
			else
				return (0);
			i++;
		}
		return (1);
}


