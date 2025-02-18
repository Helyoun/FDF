/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:02:02 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/02/18 10:25:42 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_make_map(int fd)
{
	int	**map;
	int	**tmp;
	int	*array;
	int	i;
	int	j;

	i = 0;
	while ((array = ft_split(fd)) != NULL)
	{
		tmp = malloc(sizeof(int *) *(i +2));
		j = 0;
		while (j < i)
		{
			tmp[j] = map[j];
			j++;
		}
		free(map);
		tmp[j] = array;
		map = tmp;
		i++;
	}
	map[i] = NULL;
	return (map);
}
