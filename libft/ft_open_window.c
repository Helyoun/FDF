/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 05:34:00 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/18 17:28:38 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

s_mlx	ft_mlxerror()
{
	s_mlx	mlx;

	mlx.init = NULL;
	mlx.win = NULL;
	return (mlx);
}

int	line_size(t_map *map, s_mlx mlx)
{
	int	coloms;
	int	rows;

	coloms = 0;
	rows = map->size;
	while (map != NULL)
	{
		coloms++;
		if (map->size > rows)
			rows = map->size;
		map = map->next;
	}
	coloms = mlx.height * cos(120) / coloms;
	rows = mlx.width * cos(120) / rows;
	if (rows > coloms)
		return (coloms);
	return (rows);
}

s_mlx	ft_open_window(t_map *map)
{
	s_mlx	mlx;

	mlx.init = mlx_init();
	if (mlx.init == NULL)
		return (ft_mlxerror());
	mlx_get_screen_size(mlx.init, &mlx.width, &mlx.height);
	mlx.win = mlx_new_window(mlx.init, mlx.width, mlx.height, "FDF");
	if (mlx.win == NULL)
		return (ft_mlxerror());
	mlx.line = line_size(map, mlx);
	return (mlx);
}

