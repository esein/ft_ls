/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:01:22 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/10 06:12:41 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

int			disp_once(struct s_infos *infos, struct s_space *space,
						struct s_lsopt *ls_opt)
{
	if (ls_opt->s > 0)
		disp_block(infos->stats, space);
	disp_name(infos);
	ft_put_nb_c(' ', space->name - ft_strlen(infos->name) + 1);
	return (1);
}

void		disp_colname(struct s_infos *infos, struct s_space *space,
						int max_col, struct s_lsopt *ls_opt)
{
	int				i;
	int				l;
	int				max_line;
	struct s_infos	*begin;

	i = 0;
	l = 1;
	begin = infos;
	max_line = (space->nb_files / max_col);
	max_line = ((space->nb_files % max_col) == 0) ? max_line : max_line + 1;
	while (infos != NULL)
	{
		if (((infos->index - l) % max_line) == 0)
		{
			i += disp_once(infos, space, ls_opt);
		}
		if ((i / l) == max_col)
		{
			l++;
			ft_putchar('\n');
			if (i < space->nb_files)
				infos = begin;
		}
		infos = (i >= space->nb_files && l == max_line) ? NULL : infos->next;
	}
}

void		disp_columns(struct s_infos *infos, struct s_space *space,
			struct s_lsopt *ls_opt)
{
	struct winsize	ws;
	int				max_col;
	int				max_line;
	int				i;

	i = 0;
	ioctl(0, TIOCGWINSZ, &ws);
	if (ls_opt->s > 0)
		max_col = ws.ws_col / (space->name + space->blocks + 2);
	else
		max_col = ws.ws_col / (space->name + 1);
	max_line = (space->nb_files % max_col);
	disp_colname(infos, space, max_col, ls_opt);
	if (max_line > 0)
		ft_putchar('\n');
}
