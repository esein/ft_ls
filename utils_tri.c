/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:48:42 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/09 18:24:00 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

struct s_infos		*utils_tri_ascii(struct s_infos *actual,
						struct s_infos *infos, struct s_lsopt *ls_opt)
{
	while (actual != NULL)
	{
		if (ft_strcmp(infos->name, actual->name) >= 0)
		{
			if (ls_opt->r == 0)
				break ;
		}
		else if (ls_opt->r == 1)
			break ;
		actual = actual->back;
	}
	return (actual);
}

struct s_infos		*utils_tri_size(struct s_infos *actual,
						struct s_infos *infos, struct s_lsopt *ls_opt)
{
	while (actual != NULL)
	{
		if (ls_opt->r == 0)
		{
			if (infos->FILE_SIZE < actual->FILE_SIZE)
				break ;
			else if (infos->FILE_SIZE == actual->FILE_SIZE &&
					ft_strcmp(infos->name, actual->name) >= 0)
				break ;
		}
		else if (ls_opt->r == 1)
		{
			if (infos->FILE_SIZE > actual->FILE_SIZE)
				break ;
			else if (infos->FILE_SIZE == actual->FILE_SIZE &&
					(ft_strcmp(infos->name, actual->name) <= 0))
				break ;
		}
		actual = actual->back;
	}
	return (actual);
}

struct s_infos		*utils_tri_atime(struct s_infos *actual,
						struct s_infos *infos, struct s_lsopt *ls_opt)
{
	while (actual != NULL)
	{
		if (ls_opt->r == 0)
		{
			if (infos->stats->st_atime < actual->stats->st_atime)
				break ;
			else if (infos->stats->st_atime == actual->stats->st_atime &&
					ft_strcmp(infos->name, actual->name) >= 0)
				break ;
		}
		else if (ls_opt->r == 1)
		{
			if (infos->stats->st_atime > actual->stats->st_atime)
				break ;
			else if (infos->stats->st_atime == actual->stats->st_atime &&
					(ft_strcmp(infos->name, actual->name) <= 0))
				break ;
		}
		actual = actual->back;
	}
	return (actual);
}

struct s_infos		*utils_tri_mtime(struct s_infos *actual,
						struct s_infos *infos, struct s_lsopt *ls_opt)
{
	while (actual != NULL)
	{
		if (ls_opt->r == 0)
		{
			if (infos->stats->st_mtime < actual->stats->st_mtime)
				break ;
			else if (infos->stats->st_mtime == actual->stats->st_mtime &&
					ft_strcmp(infos->name, actual->name) >= 0)
				break ;
		}
		else if (ls_opt->r == 1)
		{
			if (infos->stats->st_mtime > actual->stats->st_mtime)
				break ;
			else if (infos->stats->st_mtime == actual->stats->st_mtime &&
					ft_strcmp(infos->name, actual->name) >= 0)
				break ;
		}
		actual = actual->back;
	}
	return (actual);
}
