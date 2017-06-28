/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 08:07:44 by gcadiou           #+#    #+#             */
/*   Updated: 2017/05/22 19:33:13 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "../headerls.h"

int main()
{
//	DIR *dir;
//	struct dirent *lol;
	struct stat *stats;
//	lol = malloc(sizeof(lol));
	stats = malloc(sizeof(stats));
//	dir = opendir("/dev");
//	lol = readdir(dir);
	stat("/dev/fd", stats);
	ft_putnbr(major(stats->st_dev));
	ft_putchar('\n');
	ft_putnbr(minor(stats->st_dev));
	ft_putchar('\n');
	ft_putnbr(major(stats->st_rdev));
	ft_putchar('\n');
	ft_putnbr(minor(stats->st_rdev));
	ft_putchar('\n');
	return (0);
}
