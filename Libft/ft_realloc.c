/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:40:08 by gcadiou           #+#    #+#             */
/*   Updated: 2017/02/12 19:50:38 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size_to_malloc, size_t size_actual)
{
	void	*new;
	size_t	i;

	i = 0;
	if (ptr == NULL)
		return (0);
	new = malloc(size_to_malloc);
	ft_memmove(new, ptr, size_actual);
	free(ptr);
	return (new);
}
