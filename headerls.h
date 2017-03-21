/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:50:57 by gcadiou           #+#    #+#             */
/*   Updated: 2017/03/21 16:50:36 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERLS_H
# define HEADERLS_H

# include "Libft/Libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <time.h>
# include <stdio.h>

struct	s_lsopt
{
	char	l;
	char	R;
	char	a;
	char	r;
	char	t;
};

struct	s_space
{
	int		blocks;
	int		nlink;
	int		usr;
	int		grp;
	int		size;
};

struct	s_infos
{
	struct dirent	*file;
	struct s_space	space;
	struct stat		*stats;
	struct s_infos	*next;
};

void				open_error();

void				disp_all(struct s_infos *infos, struct s_space *space);

void				disp_simple(struct s_infos *infos, struct s_space *space);

struct s_infos		*addinfo();

struct s_infos		*stock_infos(DIR *dir, struct s_infos *infos, char *name);

int					stock_space(struct s_infos *infos, struct s_space *space);

int					info_init(struct s_infos *infos);

int					stock_arg(int argc, char **argv, struct s_lsopt *ls_opt);

int					ls_R(char *name, struct s_lsopt *ls_opt);

int					ft_ls(char *name, struct s_lsopt *ls_opt);
#endif
