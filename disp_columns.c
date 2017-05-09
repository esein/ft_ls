/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:01:22 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/09 08:15:07 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

void		disp_columns(struct s_infos *infos, struct s_space *space,
			struct s_lsopt *ls_opt)
{
	struct winsize	ws;
	int				max_col;
	int				max_line;

	ioctl(0, TIOCGWINSZ, &ws);
	if (ls_opt->s > 0)
		max_col = ws.ws_col / (space->name + space->blocks + 2);
	else
		max_col = ws.ws_col / (space->name + 1);
	max_line = max_col / space->nb_files;
}
