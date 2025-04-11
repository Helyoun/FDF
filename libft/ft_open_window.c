/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 05:34:00 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/11 04:22:40 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_open_window(void **mlx, void	**win, void **img)
{
	*mlx = mlx_init();
	if (*mlx == NULL)
		return ;
	*win = mlx_new_window(*mlx, WIDTH, HEIGHT, "FDF");
	*img = mlx_new_image(*mlx, WIDTH, HEIGHT);
	if (win == NULL || img == NULL)
	{
		win = NULL;
		img = NULL;
	}
}

