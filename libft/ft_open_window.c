/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 05:34:00 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/19 17:22:46 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "libft.h"

t_mlx	ft_mlxnull(void)
{
	t_mlx	mlx;

	mlx.init = NULL;
	mlx.win = NULL;
	mlx.img = NULL;
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

void	ft_mlxerror(t_map *map, t_mlx mlx)
{
	ft_putstr_fd("ERROR ON OPENING WINDOW\n", 2);
	ft_free_map(&map);
	if (mlx.init == NULL)
		exit(1);
	if (mlx.win != NULL)
		mlx_destroy_window(mlx.init, mlx.win);
	if (mlx.init == NULL)
		mlx_destroy_image(mlx.init, mlx.img);
	mlx_destroy_display(mlx.init);
	free(mlx.init);
	exit(1);
}

t_mlx	ft_open_window(t_map *map)
{
	t_mlx	mlx;

	mlx = ft_mlxnull();
	mlx.init = mlx_init();
	if (mlx.init == NULL)
		ft_mlxerror(map, mlx);
	mlx_get_screen_size(mlx.init, &mlx.width, &mlx.height);
	mlx.win = mlx_new_window(mlx.init, mlx.width, mlx.height, "FDF");
	mlx.img = mlx_new_image(mlx.init, mlx.width, mlx.height);
	if (mlx.win == NULL || mlx.img == NULL || mlx.init == NULL)
		ft_mlxerror(map, mlx);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp,
			&mlx.line_length, &mlx.endian);
	mlx.line = line_size(map, mlx);
	return (mlx);
}
