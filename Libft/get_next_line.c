/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:17:41 by gcadiou           #+#    #+#             */
/*   Updated: 2017/06/28 16:09:15 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int				old_to_new(t_gnl *gnl)
{
	int		i;
	int		i2;
	char	*tmp;

	i = 0;
	i2 = 0;
	check_malloc(gnl->str_new = malloc(sizeof(char) *
			(1 + ft_strlentil(gnl->str_old, '\n', 0))), "gnl: old_to_new");
	while (gnl->str_old[i])
	{
		if ((gnl->ret = 1) && gnl->str_old[i] == '\n')
		{
			gnl->str_new[i++] = '\0';
			tmp = ft_strsub(gnl->str_old, i, ft_strlen(&gnl->str_old[i]));
			free(gnl->str_old);
			gnl->str_old = tmp;
			return (1);
		}
		gnl->str_new[i2] = gnl->str_old[i];
		i++;
		i2++;
	}
	gnl->str_new[i] = '\0';
	free(gnl->str_old);
	return (0);
}

int				read_and_add(const int fd, t_gnl *gnl)
{
	char	buf[BUFF_SIZE + 1];
	int		i;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		gnl->ret = 1;
		i = 0;
		buf[ret] = '\0';
		while (buf[i] != '\n' && i < ret)
			i++;
		gnl->str_new = ft_realloc(gnl->str_new, sizeof(char) *
				(ft_strlen(gnl->str_new) + i + 1), ft_strlen(gnl->str_new) + 1);
		ft_strncat(gnl->str_new, buf, i);
		if (buf[i] == '\n')
		{
			i++;
			check_malloc(gnl->str_old = malloc(sizeof(char) *
						(ft_strlen(&buf[i]) + 1)), "gnl: read_and_add");
			ft_strcpy(gnl->str_old, &buf[i]);
			return (1);
		}
	}
	return (ret);
}

int				wicheone(int fd, t_gnl **gnl)
{
	int		i;

	i = 0;
	while (((*gnl)[i]).fd != fd)
	{
		if (((*gnl)[i]).last == 1)
		{
			((*gnl)[i]).last = 0;
			i++;
			*gnl = (t_gnl*)ft_realloc(*gnl, (sizeof(t_gnl) * (i + 1)),
						sizeof(t_gnl) * i);
			((*gnl)[i]).fd = fd;
			((*gnl)[i]).last = 1;
			return (i);
		}
		i++;
	}
	return (i);
}

static	void	vivelanorme2(t_gnl *gnl)
{
	gnl->ret = 0;
	check_malloc(gnl->str_new = (char *)malloc(sizeof(char)),
			"gnl: vivelanorme2");
	gnl->str_new[0] = '\0';
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	int				act;

	if (fd < 0 || line == NULL)
		return (-1);
	if (gnl == NULL)
	{
		check_malloc(gnl = (t_gnl*)malloc(sizeof(t_gnl) * 1),
				"gnl: get_next_line");
		gnl[0].last = 1;
		gnl[0].fd = fd;
	}
	act = wicheone(fd, &gnl);
	vivelanorme2(&(gnl[act]));
	if (gnl[act].notfirst == 1)
		if (old_to_new(&(gnl[act])))
		{
			*line = gnl[act].str_new;
			return (1);
		}
	gnl[act].notfirst = read_and_add(fd, &(gnl[act]));
	*line = gnl[act].str_new;
	if (gnl[act].notfirst == -1)
		return (-1);
	return (gnl[act].ret);
}
