/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:07:05 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/18 16:36:09 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

void				init_arg(struct s_lsopt *ls_opt)
{
	ls_opt->one = 0;
	ls_opt->l = 0;
	ls_opt->R = 0;
	ls_opt->a = 0;
	ls_opt->r = 0;
	ls_opt->t = 0;
	ls_opt->u = 0;
	ls_opt->s = 0;
	ls_opt->S = 0;
	ls_opt->f = 0;
	ls_opt->G = 0;
}

void				list_swap(struct s_infos *infos)
{
	char			*name_tmp;
	char			*lnk_name_tmp;
	struct stat		*stats_tmp;

	name_tmp = infos->name;
	lnk_name_tmp = infos->lnk_name;
	stats_tmp = infos->stats;
	infos->name = infos->next->name;
	infos->lnk_name = infos->next->lnk_name;
	infos->stats = infos->next->stats;
	infos->next->name = name_tmp;
	infos->next->lnk_name = lnk_name_tmp;
	infos->next->stats = stats_tmp;
}

void				info_init(struct s_infos *infos)
{
		infos->next = NULL;
		infos->name = NULL;
		infos->stats = NULL;
		infos->lnk_name = NULL;
}

struct s_infos		*addinfo()
{
	struct s_infos		*new;

	new = NULL;
	check_malloc(new = (struct s_infos*)malloc(sizeof(struct s_infos)),
			"ls: addinfo");
	info_init(new);
	return (new);
}
