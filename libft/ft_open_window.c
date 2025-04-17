/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 05:34:00 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/17 18:09:44 by hamel-yo         ###   ########.fr       */
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

s_mlx	ft_open_window()
{
	s_mlx	mlx;

	mlx.init = mlx_init();
	if (mlx.init == NULL)
		return (ft_mlxerror());
	mlx_get_screen_size(mlx.init, &mlx.width, &mlx.height);
	mlx.win = mlx_new_window(mlx.init, mlx.width, mlx.height, "FDF");
	if (mlx.win == NULL)
		return (ft_mlxerror());
	return (mlx);
}

