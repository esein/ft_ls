/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:01:22 by gcadiou           #+#    #+#             */
/*   Updated: 2017/06/28 17:17:08 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

int			disp_once(struct s_infos *infos, struct s_space *space,
						struct s_lsopt *ls_opt)
{
	if (ls_opt->s > 0)
		disp_block(infos->stats, space);
	disp_name(infos, ls_opt);
	ft_put_nb_c(' ', space->name - ft_strlen(infos->name) + 1);
	return (1);
}

void		disp_colname(struct s_infos *infos, struct s_space *space,
						struct s_varcol *var_col, struct s_lsopt *ls_opt)
{
	struct s_infos	*begin;

	var_col->c = 0;
	var_col->n = 0;
	var_col->l = 0;
	begin = infos;
	while (infos != NULL)
	{
		if ((var_col->i - var_col->l) % var_col->max_line == 0)
		{
			var_col->c += disp_once(infos, space, ls_opt);
			var_col->n++;
		}
		var_col->i++;
		infos = infos->next;
		if ((var_col->c == var_col->max_col && var_col->n < space->nb_files) ||
			(infos == NULL && var_col->n < space->nb_files))
		{
			var_col->c = 0;
			var_col->i = 0;
			var_col->l++;
			ft_putchar('\n');
			infos = begin;
		}
	}
}

int			disp_columns(struct s_infos *infos, struct s_space *space,
			struct s_lsopt *ls_opt)
{
	struct winsize	ws;
	struct s_varcol	var_col;

	var_col.i = 0;
	ioctl(0, TIOCGWINSZ, &ws);
	if (ws.ws_col < (space->name + space->blocks + 2))
	{
		disp_list(infos, space, ls_opt);
		return (0);
	}
	if (ls_opt->s > 0)
		var_col.max_col = ws.ws_col / (space->name + space->blocks + 2);
	else
		var_col.max_col = ws.ws_col / (space->name + 1);
	var_col.max_line = (space->nb_files / var_col.max_col);
	var_col.max_line = ((space->nb_files % var_col.max_col) == 0) ?
						var_col.max_line : var_col.max_line + 1;
	disp_colname(infos, space, &var_col, ls_opt);
	if (var_col.max_line > 0)
		ft_putchar('\n');
	return (0);
}
