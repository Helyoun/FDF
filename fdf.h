/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:24:20 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/19 15:50:55 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

# define WIDTH 1920
# define HEIGHT 1080
# define LINE 50

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

typedef struct s_mlx
{
	int		line;
	int		height;
	int		width;
	int		bpp;
	int		line_length;
	int		endian;
	char	*addr;
	void	*img;
	void	*init;
	void	*win;
}	t_mlx;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;

typedef struct s_map
{
	short			*row;
	short			size;
	struct s_map	*next;
}	t_map;

typedef struct s_close
{
	t_map	*map;
	t_mlx	mlx;
}	t_close;

float	isometric_x(int x, int y);
char	*get_next_line(int fd);
t_mlx	ft_open_window(t_map *map);
void	isometric(t_point a, t_point b, t_mlx mlx);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
int		ft_isoprator(int c);

#endif
