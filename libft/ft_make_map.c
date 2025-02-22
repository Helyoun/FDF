/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:02:02 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/02/22 09:59:22 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_make_map(int fd)
{
	t_list	*map;
	t_list	*save;
	t_list	*tmp;

	map = NULL;
	while (1)
	{
		tmp = ft_make_node(fd, &map);
		if (map == NULL)
		{
			map = tmp;
			save = map;
		}
		else
		{
			map->next = tmp;
			map = map->next;
		}
		if (tmp == NULL)
			break ;
	}
	return (save);
}
