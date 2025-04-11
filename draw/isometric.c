/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:43:00 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/11 04:46:56 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(char x, char y, char z, s_mlx mlx, int i)
{
	float	nx;
	float	ny;
	nx = (x - y) * cos(i);
	ny = (x + y) * sin(i) - z;
	mlx_pixel_put(mlx.init, mlx.win, 550 + (nx * 10), 550 + (ny * 10), 0xFF0000);
}
