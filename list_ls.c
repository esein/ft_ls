/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:07:05 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/09 17:41:45 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

struct s_infos	*lswap(struct s_infos *actual, struct s_infos *infos,
						struct s_infos *first)
{
	infos->back->next = infos->next;
	if (infos->next != NULL)
	{
		infos->next->back = infos->back;
	}
	if (actual != NULL)
	{
		infos->next = actual->next;
		infos->back = actual;
		if (actual->next != NULL)
			actual->next->back = infos;
		actual->next = infos;
	}
	else
	{
		infos->next = first;
		infos->back = NULL;
		first->back = infos;
		first = infos;
	}
	return (first);
}

void			init_arg(struct s_lsopt *ls_opt)
{
	ls_opt->one = 0;
	ls_opt->l = 0;
	ls_opt->br = 0;
	ls_opt->a = 0;
	ls_opt->r = 0;
	ls_opt->t = 0;
	ls_opt->u = 0;
	ls_opt->s = 0;
	ls_opt->bs = 0;
	ls_opt->f = 0;
	ls_opt->bg = 0;
}

void			info_init(struct s_infos *infos)
{
	infos->next = NULL;
	infos->name = NULL;
	infos->stats = NULL;
	infos->lnk_name = NULL;
}

struct s_infos	*addinfo(struct s_infos *infos)
{
	struct s_infos		*new;

	new = NULL;
	check_malloc(new = (struct s_infos*)malloc(sizeof(struct s_infos)),
			"ls: addinfo");
	info_init(new);
	new->back = infos;
	return (new);
}
