/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:39:02 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/11 04:26:33 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	operror(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

t_map	*ft_open_file(char *s, int *rows)
{
	int	fd;

	fd = open (s, O_RDWR);
	if (ft_strcmp(s, ".fdf") != 0 || fd <= -1)
		operror("Map Error: Failed to open map tiles");
	return (ft_make_map(fd, rows));
}
