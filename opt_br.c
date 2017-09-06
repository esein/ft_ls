/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_br.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:18:52 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/04 18:57:17 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

int			ls_br(char *name, struct s_lsopt *ls_opt)
{
	struct s_infos	*infos;
	struct s_infos	*actual;

	if ((infos = ft_ls(name, ls_opt)) == NULL)
		return (0);
	actual = infos;
	while (actual != NULL)
	{
		if (S_ISDIR(actual->stats->st_mode) &&
				(ft_strcmp(actual->name, ".") &&
				(ft_strcmp(actual->name, ".."))))
		{
			ft_putchar('\n');
			ft_putendl(ft_strjoin(name, ft_strjoin(actual->name, ":")));
			ls_br(ft_strjoin(name, ft_strjoin(actual->name, "/")), ls_opt);
		}
		actual = actual->next;
	}
	return (0);
}
