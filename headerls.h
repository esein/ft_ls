/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 01:50:57 by gcadiou           #+#    #+#             */
/*   Updated: 2017/09/05 21:26:20 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERLS_H
# define HEADERLS_H

# include "Libft/libft.h"
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
# define MODE infos->stats->st_mode

# define C_DIR S_CYAN
# define C_LNK MAGENTA
# define C_SOCK GREEN
# define C_FIFO BROWN
# define C_EXEC RED
# define C_BLK BLUE_B_CYAN
# define C_CHR BLUE_B_BROWN
# define C_SUID BLACK_B_RED
# define C_SGID BLACK_B_CYAN
# define C_WSDIR BLACK_B_GREEN
# define C_WDIR BLACK_B_BROWN

struct				s_varcol
{
	int	i;
	int l;
	int	n;
	int c;
	int	max_line;
	int	max_col;
};

struct				s_lsopt
{
	int	one;
	int	bg;
	int	br;
	int	bs;
	int	a;
	int	f;
	int	l;
	int	r;
	int	t;
	int	u;
	int	s;
};

struct				s_space
{
	int		blocks;
	int		nlink;
	int		usr;
	int		grp;
	int		size;
	int		total;
	int		name;
	int		nb_files;
	int		majeur;
	int		mineur;
};

struct				s_infos
{
	int				index;
	char			*name;
	char			*lnk_name;
	struct stat		*stats;
	struct s_infos	*next;
	struct s_infos	*back;
};

void				disp_dev(struct stat *stats, struct s_space *space);

void				disp_list(struct s_infos *infos, struct s_space *space,
								struct s_lsopt *ls_opt);

void				disp_name(struct s_infos *infos, struct s_lsopt *ls_opt);

void				disp_block(struct stat *stats, struct s_space *space);

int					disp_columns(struct s_infos *infos, struct s_space *space,
								struct s_lsopt *ls_opt);

void				disp_time(struct stat *stats, struct s_lsopt *ls_opt);

void				init_arg(struct s_lsopt *ls_opt);

struct s_infos		*check_tri(struct s_infos *infos, struct s_lsopt *ls_opt);

void				tri_atime(struct s_infos *infos, struct s_lsopt *ls_opt);

void				tri_mtime(struct s_infos *infos, struct s_lsopt *ls_opt);

void				tri_size(struct s_infos *infos, struct s_lsopt *ls_opt);

void				list_swap(struct s_infos *infos);

void				*open_error(char *name);

void				arg_error(char arg);

void				disp_l(struct s_infos *infos, struct s_space *space,
							struct s_lsopt *ls_opt);

void				disp_simple(struct s_infos *infos, struct s_space *space,
								struct s_lsopt *ls_opt);

void				disp_divers(struct stat *stats, struct s_space *space);

void				disp_mode(struct stat *stats);

void				disp_total(struct s_space *space);

struct s_infos		*tri_ascii(struct s_infos *infos, struct s_lsopt *ls_opt);

struct s_infos		*addinfo();

struct s_infos		*stock_infos(DIR *dir, struct s_infos *infos, char *name,
								struct s_lsopt *ls_opt);

int					stock_space(struct s_infos *infos, struct s_space *space,
								struct s_lsopt *ls_opt);

void				info_init(struct s_infos *infos);

void				stock_index(struct s_infos *infos, struct s_lsopt *ls_opt,
								struct s_space *space);

int					stock_arg(int argc, char **argv, struct s_lsopt *ls_opt);

int					ls_br(char *name, struct s_lsopt *ls_opt);

struct s_infos		*ft_ls(char *name, struct s_lsopt *ls_opt);
#endif
