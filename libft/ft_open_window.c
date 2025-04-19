/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 05:34:00 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/19 15:11:31 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_mlx	ft_mlxerror(void)
{
	t_mlx	mlx;

	mlx.init = NULL;
	mlx.win = NULL;
	return (mlx);
}

int	line_size(t_map *map, t_mlx mlx)
{
	int	i;
	int	row;

	row = map->size;
	i = 0;
	while ((isometric_x(row, 0) * i + (mlx.width / 10)) < mlx.height)
		i++;
	return (i);
}

t_mlx	ft_open_window(t_map *map)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	if (mlx.init == NULL)
		return (ft_mlxerror());
	mlx_get_screen_size(mlx.init, &mlx.width, &mlx.height);
	mlx.win = mlx_new_window(mlx.init, mlx.width, mlx.height, "FDF");
	mlx.img = mlx_new_image(mlx.init, mlx.width, mlx.height);
	if (mlx.win == NULL || mlx.img == NULL)
	{
		free(mlx.img);
		return (ft_mlxerror());
	}
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp,
			&mlx.line_length, &mlx.endian);
	mlx.line = line_size(map, mlx);
	return (mlx);
}
