/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:18:21 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/19 16:48:47 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_points(t_mlx mlx, t_map *map, int i, int j)
{
	t_point	a;
	t_point	b;

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

void	ft_draw(t_map *map, t_mlx mlx)
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
	mlx_put_image_to_window(mlx.init, mlx.win, mlx.img, 0, 0);
}

int	close_window(t_close *data)
{
	ft_free_map(&(data->map));
	mlx_destroy_window((data->mlx).init, (data->mlx).win);
	mlx_destroy_image((data->mlx).init, (data->mlx).img);
	mlx_destroy_display((data->mlx).init);
	free((data->mlx).init);
	exit(0);
}

int	key_handler(int key, t_close *data)
{
	if (key == 65307)
	{
		ft_free_map(&(data->map));
		mlx_destroy_window((data->mlx).init, (data->mlx).win);
		mlx_destroy_image((data->mlx).init, (data->mlx).img);
		mlx_destroy_display((data->mlx).init);
		free((data->mlx).init);
		exit(0);
	}
	return (0);
}

int	main(int c, char **v)
{
	t_map	*map;
	t_mlx	mlx;
	t_close	data;

	map = openfile(c, v);
	if (map == NULL)
	{
		ft_putstr_fd("ERROR ON READING MAP\n", 2);
		return (0);
	}
	mlx = ft_open_window(map);
	data.map = map;
	data.mlx = mlx;
	ft_draw(map, mlx);
	mlx_key_hook(mlx.win, key_handler, &data);
	mlx_hook(mlx.win, 17, 0, close_window, &data);
	mlx_loop(mlx.init);
}
