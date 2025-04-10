/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 23:57:49 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/09 18:13:09 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(int x, int y, int z, void *init, void *win, int i);

int	main (int c, char **v)
{
	int	z = atoi(v[3]);
	int	i = atoi(v[1]);
	int	j = atoi(v[2]);
	int	al = atoi(v[4]);

	printf("%d %d %d %d\n", i, j, z, al);
	void	*init;
	void	*win;
	init = mlx_init();
	win = mlx_new_window(init, 1920, 1080, "test");
	while (j <= 10 && i <= 10 && z <= 10)
	{
		if (i == 5)
			z = 10;
		isometric(i, j , z, init , win, al);
		if (i > 0)
			i++;
		else if (z > 0)
			z++;
		else
			j++;
	}
	while (1);
}
