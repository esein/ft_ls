/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:50:57 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/09 07:58:26 by gcadiou          ###   ########.fr       */
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
# include <errno.h>
# include <sys/ioctl.h>

# define FILE_SIZE stats->st_size

struct	s_lsopt
{
	char	one;
	char	l;
	char	R;
	char	a;
	char	r;
	char	t;
	char	u;
	char	s;
	char	S;
	char	f;
};

struct	s_space
{
	int		blocks;
	int		nlink;
	int		usr;
	int		grp;
	int		size;
	int		total;
	int		name;
	int		nb_files;
};

struct	s_infos
{
	int				index;
	char			*name;
	char			*lnk_name;
	struct stat		*stats;
	struct s_infos	*next;
};

void				disp_columns(struct s_infos *infos, struct s_space *space,
								struct s_lsopt *ls_opt);

void				disp_time(struct stat *stats, struct s_space *space,
							struct s_lsopt *ls_opt);

void				init_arg(struct s_lsopt *ls_opt);

void				check_tri(struct s_infos *infos, struct s_lsopt *ls_opt);

void				tri_atime(struct s_infos *infos, struct s_lsopt *ls_opt);

void				tri_mtime(struct s_infos *infos, struct s_lsopt *ls_opt);

void				tri_size(struct s_infos *infos, struct s_lsopt *ls_opt);

void				tri_ascii(struct s_infos *infos, struct s_lsopt *ls_opt);

void				list_swap(struct s_infos *infos);

void				*open_error(char *name);

void				disp_all(struct s_infos *infos, struct s_space *space,
							struct s_lsopt *ls_opt);

void				disp_simple(struct s_infos *infos, struct s_space *space,
								struct s_lsopt *ls_opt);

void				disp_divers(struct stat *stats, struct s_space *space);

void				disp_mode(struct stat *stats);

void				disp_total(struct s_space *space);

struct s_infos		*addinfo();

struct s_infos		*stock_infos(DIR *dir, struct s_infos *infos, char *name);

int					stock_space(struct s_infos *infos, struct s_space *space,
								struct s_lsopt *ls_opt);

void				info_init(struct s_infos *infos);

void				stock_index(struct s_infos *infos, struct s_lsopt *ls_opt,
								struct s_space *space);

int					stock_arg(int argc, char **argv, struct s_lsopt *ls_opt);

int					ls_R(char *name, struct s_lsopt *ls_opt);

struct s_infos		*ft_ls(char *name, struct s_lsopt *ls_opt);
#endif
