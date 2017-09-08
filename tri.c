/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:06:29 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/06 21:50:12 by gcadiou          ###   ########.fr       */
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

struct s_infos	*tri_ascii(struct s_infos *actual, struct s_lsopt *ls_opt)
{
	struct s_infos		*infos;
	struct s_infos		*first;
	struct s_infos		*save;

	first = actual;
	infos = actual->next;
	while (infos != NULL)
	{
		while (actual != NULL)
		{
			if (ft_strcmp(infos->name, actual->name) >= 0)
			{
				if (ls_opt->r == 0)
					break;
			}
			else
				if (ls_opt->r == 1)
					break;
			actual = actual->back;
		}
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
		while (actual != NULL)
		{
			if (ls_opt->r == 0)
			{
				if (infos->FILE_SIZE < actual->FILE_SIZE)
					break;
				else if (infos->FILE_SIZE == actual->FILE_SIZE &&
							ft_strcmp(infos->name, actual->name) >= 0)
					break;
			}
			else if (ls_opt->r == 1)
			{
				if (infos->FILE_SIZE > actual->FILE_SIZE)
					break;
				else if (infos->FILE_SIZE == actual->FILE_SIZE &&
							(ft_strcmp(infos->name, actual->name) <= 0))
					break;
			}
			actual = actual->back;
		}
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
		while (actual != NULL)
		{
			if (ls_opt->r == 0)
			{
				if (infos->stats->st_atime < actual->stats->st_atime)
					break;
			else if (infos->stats->st_atime == actual->stats->st_atime &&
						ft_strcmp(infos->name, actual->name) >= 0)
				break;
			}
			else if (ls_opt->r == 1)
			{
				if (infos->stats->st_atime > actual->stats->st_atime)
					break;
				else if (infos->stats->st_atime == actual->stats->st_atime &&
						(ft_strcmp(infos->name, actual->name) <= 0))
					break;
			}
					actual = actual->back;
		}
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
		while (actual != NULL)
		{
			if (ls_opt->r == 0)
			{
				if (infos->stats->st_mtime < actual->stats->st_mtime)
					break;
				else if (infos->stats->st_mtime == actual->stats->st_mtime &&
							ft_strcmp(infos->name, actual->name) >= 0)
					break;
			}
			else if (ls_opt->r == 1)
			{
				if (infos->stats->st_mtime > actual->stats->st_mtime)
					break;
				else if (infos->stats->st_mtime == actual->stats->st_mtime &&
							ft_strcmp(infos->name, actual->name) >= 0)
					break;
			}
			else
				if (ls_opt->r == 1)
					break;
			actual = actual->back;
		}
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
