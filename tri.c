/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:06:29 by gcadiou           #+#    #+#             */
/*   Updated: 2017/04/26 10:58:19 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

void		tri_ascii(struct s_infos *infos, struct s_lsopt *ls_opt)
{
	struct s_infos		*first;

	first = infos;
	if (ls_opt->r > 0)
		while (infos->next != NULL)
		{
			if (ft_strcmp(infos->name, infos->next->name) < 0)
			{
				list_swap(infos);
				infos = first;
			}
			else
				infos = infos->next;
		}
	else
		while (infos->next != NULL)
		{
			if (ft_strcmp(infos->name, infos->next->name) > 0)
			{
				list_swap(infos);
				infos = first;
			}
			else
				infos = infos->next;
		}
}

void		tri_size(struct s_infos *infos, struct s_lsopt *ls_opt)
{
	struct s_infos		*first;

	first = infos;
	if (ls_opt->r > 0)
		while (infos->next != NULL)
		{
			if (infos->FILE_SIZE > infos->next->FILE_SIZE)
			{
				list_swap(infos);
				infos = first;
			}
			else
				infos = infos->next;
		}
	else
		while (infos->next != NULL)
		{
			if (infos->FILE_SIZE < infos->next->FILE_SIZE)
			{
				list_swap(infos);
				infos = first;
			}
			else
				infos = infos->next;
		}
}

void		tri_atime(struct s_infos *infos, struct s_lsopt *ls_opt)
{
	struct s_infos		*first;

	first = infos;
	if (ls_opt->r > 0)
		while (infos->next != NULL)
		{
			if (infos->stats->st_atime > infos->next->stats->st_atime)
			{
				list_swap(infos);
				infos = first;
			}
			else
				infos = infos->next;
		}
	else
		while (infos->next != NULL)
		{
			if (infos->stats->st_atime < infos->next->stats->st_atime)
			{
				list_swap(infos);
				infos = first;
			}
			else
				infos = infos->next;
		}
}

void		tri_mtime(struct s_infos *infos, struct s_lsopt *ls_opt)
{
	struct s_infos		*first;

	first = infos;
	if (ls_opt->r > 0)
		while (infos->next != NULL)
		{
			if (infos->stats->st_mtime > infos->next->stats->st_mtime)
			{
				list_swap(infos);
				infos = first;
			}
			else
				infos = infos->next;
		}
	else
		while (infos->next != NULL)
		{
			if (infos->stats->st_mtime < infos->next->stats->st_mtime)
			{
				list_swap(infos);
				infos = first;
			}
			else
				infos = infos->next;
		}
}

void		check_tri(struct s_infos *infos, struct s_lsopt *ls_opt)
{
	if (ls_opt->f == 0)
	{
		tri_ascii(infos, ls_opt);
		if (ls_opt->t > 0)
		{
			if (ls_opt->u > 0)
				tri_atime(infos, ls_opt);
			else
				tri_mtime(infos, ls_opt);
		}
		else if (ls_opt->S > 0)
			tri_size(infos, ls_opt);
	}
}
