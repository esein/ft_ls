/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_R.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 02:53:37 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/09 04:36:11 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

int			ls_R(char *name, struct s_lsopt *ls_opt)
{
	DIR				*dir;
	struct s_infos	*infos;
	struct s_infos	*actual;

	if ((infos = ft_ls(name, ls_opt)) == NULL)
		return (0);
	actual = infos;
	while (actual != NULL)
	{
		if (actual->name[0] != '.' || ls_opt->a != 0)
			if (S_ISDIR(actual->stats->st_mode) &&
			(ft_strcmp(actual->name, ".") && (ft_strcmp(actual->name, ".."))))
			{
				ft_putchar('\n');
				ft_putendl(ft_strjoin(name, ft_strjoin(actual->name, ":")));
				ls_R(ft_strjoin(name, ft_strjoin(actual->name, "/")), ls_opt);
			}
		actual = actual->next;
	}
	return (0);
}
