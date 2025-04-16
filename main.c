/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 05:14:19 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/11 21:44:02 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int c, char **v)
{
	t_map	*map;
	int	rows;
	char	i;
	char	j;
	s_mlx	mlx;

	rows = 0;
	if (c != 2)
		return (1);
	map = ft_open_file(v[1], &rows);
	printf("%d\n", rows);
	mlx = ft_open_window();
	j =  0;
	while (map != NULL)
	{
		i = 0;
		while (i < map->size)
		{
			isometric(i, j, map->row[i], mlx, 120);//printf("%d ", i);
			i++;
		}
		map = map->next;
		j++;
	}
	while (1);
}
