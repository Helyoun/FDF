/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:43:00 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/18 17:22:20 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	isometric_x(int	x, int	y)
{
	return ((x - y) * cos(120));
}

float	isometric_y(int	x, int	y, int z)
{
	return ((x + y) * sin(120) - z);
}

void	ft_draw_line(s_point a, s_point b, float steps, s_mlx mlx)
{
	float	i;

	i = 0;
	a.z = a.z / steps;
	b.z = b.z / steps;
	while (i <= steps)
	{
		mlx_pixel_put(mlx.init, mlx.win, 500 + a.x, 500 + a.y, 0xFFFFFF);
		a.x += a.z;
		a.y += b.z;
		i++;
	}
}

void	isometric(s_point a, s_point b, s_mlx mlx)
{
	float	tmp;

	tmp = a.x;
	a.x = isometric_x(a.x, a.y) * mlx.line;
	a.y = isometric_y(tmp, a.y, a.z) * mlx.line;
	tmp = b.x;
	b.x = isometric_x(b.x, b.y)* mlx.line;
	b.y = isometric_y(tmp, b.y, b.z) * mlx.line;
	a.z = b.x - a.x;
	b.z = b.y - a.y;
	if (fabs(b.z) > fabs(a.z))
		tmp = fabs(b.z);
	else
		tmp = fabs(a.z);
	ft_draw_line(a, b, tmp, mlx);
}
