/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:18:21 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/18 17:00:52 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_points(s_mlx mlx, t_map *map, int i, int j)
{
	s_point	a;
	s_point	b;

	a.x = (float)i;
	a.y = (float)j;
	a.z = (map->row)[i];
	if (i + 1 < map->size)
	{
		b.x = (float)(i + 1);
		b.y = (float)j;
		b.z = (map->row)[i + 1];
		isometric(a, b, mlx);
	}
	if (map->next != NULL)
	{
		b.x = (float)(i);
		b.y = (float)(j + 1);
		b.z = map->next->row[i];
		isometric(a, b, mlx);
	}
}

void	ft_draw(t_map *map, s_mlx mlx)
{
	int	i;
	int	j;

	j = 0;
	while (map != NULL)
	{
		i = 0;
		while (i < map->size)
		{
			init_points(mlx, map, i, j);
			i++;
		}
		map = map->next;
		j++;
	}
}

int	main (int c, char **v)
{
	t_map	*map;
	t_map	*tmp;
	s_mlx	mlx;

	map = openfile(c, v);
	mlx = ft_open_window(map);
	ft_draw(map, mlx);
	while(1);
}
