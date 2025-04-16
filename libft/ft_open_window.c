/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 05:34:00 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/11 04:51:34 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

s_mlx	ft_mlxerror()
{
	s_mlx	mlx;

	mlx.init = NULL;
	mlx.win = NULL;
	mlx.img = NULL;
	return (mlx);
}

s_mlx	ft_open_window()
{
	s_mlx	mlx;

	mlx.init = mlx_init();
	if (mlx.init == NULL)
		return (ft_mlxerror());
	mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGHT, "FDF");
	mlx.img = mlx_new_image(mlx.init, WIDTH, HEIGHT);
	if (mlx.win == NULL || mlx.img == NULL)
		return (ft_mlxerror());
	return (mlx);
}

