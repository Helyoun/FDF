/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:43:00 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/19 15:23:35 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	isometric_x(int x, int y)
{
	return ((x - y) * cos(120));
}

float	isometric_y(int x, int y, int z)
{
	return ((x + y) * sin(120) - z);
}

void	my_mlx_pixel_put(t_mlx mlx, int x, int y, int color)
{
	char	*dst;

	if (x > mlx.width || y > mlx.height || x < 0 || y < 0)
		return ;
	dst = mlx.addr + (y * mlx.line_length + x * (mlx.bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_line(t_point a, t_point b, float steps, t_mlx mlx)
{
	float	i;

	i = 0;
	a.z = a.z / steps;
	b.z = b.z / steps;
	while (i <= steps)
	{
		my_mlx_pixel_put(mlx, (mlx.width / 3) + a.x,
			(mlx.height / 10) + a.y, 0xFFFFFF);
		a.x += a.z;
		a.y += b.z;
		i++;
	}
}

void	isometric(t_point a, t_point b, t_mlx mlx)
{
	float	tmp;

	tmp = a.x;
	a.x = isometric_x(a.x, a.y) * mlx.line;
	a.y = isometric_y(tmp, a.y, a.z) * mlx.line;
	tmp = b.x;
	b.x = isometric_x(b.x, b.y) * mlx.line;
	b.y = isometric_y(tmp, b.y, b.z) * mlx.line;
	a.z = b.x - a.x;
	b.z = b.y - a.y;
	if (fabs(b.z) > fabs(a.z))
		tmp = fabs(b.z);
	else
		tmp = fabs(a.z);
	ft_draw_line(a, b, tmp, mlx);
}
