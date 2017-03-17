/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:07:05 by gcadiou           #+#    #+#             */
/*   Updated: 2017/03/17 08:54:35 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerls.h"

int					info_init(struct s_infos *infos)
{
		infos->next = NULL;
		infos->file = NULL;
		infos->stats = NULL;
		return (0);
}

struct s_infos		*addinfo()
{
	struct s_infos		*new;

	new = NULL;
	if (!(new = (struct s_infos*)malloc(sizeof(struct s_infos))))
		return (NULL);
	info_init(new);
	return (new);
}
