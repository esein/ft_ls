/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:06:29 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/09 18:05:14 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

struct s_infos	*tri_ascii(struct s_infos *actual, struct s_lsopt *ls_opt)
{
	struct s_infos		*infos;
	struct s_infos		*first;
	struct s_infos		*save;

	first = actual;
	infos = actual->next;
	while (infos != NULL)
	{
		actual = utils_tri_ascii(actual, infos, ls_opt);
		save = infos->next;
		first = lswap(actual, infos, first);
		infos = save;
		if (infos != NULL)
			actual = infos->back;
	}
	return (first);
}

struct s_infos	*tri_size(struct s_infos *actual, struct s_lsopt *ls_opt)
{
	struct s_infos		*infos;
	struct s_infos		*first;
	struct s_infos		*save;

	first = actual;
	infos = actual->next;
	while (infos != NULL)
	{
		actual = utils_tri_size(actual, infos, ls_opt);
		save = infos->next;
		first = lswap(actual, infos, first);
		infos = save;
		if (infos != NULL)
			actual = infos->back;
	}
	return (first);
}

struct s_infos	*tri_atime(struct s_infos *actual, struct s_lsopt *ls_opt)
{
	struct s_infos		*infos;
	struct s_infos		*first;
	struct s_infos		*save;

	first = actual;
	infos = actual->next;
	while (infos != NULL)
	{
		actual = utils_tri_atime(actual, infos, ls_opt);
		save = infos->next;
		first = lswap(actual, infos, first);
		infos = save;
		if (infos != NULL)
			actual = infos->back;
	}
	return (first);
}

struct s_infos	*tri_mtime(struct s_infos *actual, struct s_lsopt *ls_opt)
{
	struct s_infos		*infos;
	struct s_infos		*first;
	struct s_infos		*save;

	first = actual;
	infos = actual->next;
	while (infos != NULL)
	{
		actual = utils_tri_mtime(actual, infos, ls_opt);
		save = infos->next;
		first = lswap(actual, infos, first);
		infos = save;
		if (infos != NULL)
			actual = infos->back;
	}
	return (first);
}

struct s_infos	*check_tri(struct s_infos *infos, struct s_lsopt *ls_opt)
{
	if (ls_opt->f == 0)
	{
		if (ls_opt->bs > 0)
			infos = tri_size(infos, ls_opt);
		else if (ls_opt->t > 0)
		{
			if (ls_opt->u > 0)
				infos = tri_atime(infos, ls_opt);
			else
				infos = tri_mtime(infos, ls_opt);
		}
		else
			infos = tri_ascii(infos, ls_opt);
	}
	return (infos);
}
