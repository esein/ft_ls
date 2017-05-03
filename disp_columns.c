/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_columns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:01:22 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/03 19:58:59 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

void		disp_columns(struct s_infos *infos, struct s_space *space, struct s_lsopt *ls_opt)
{
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
}
