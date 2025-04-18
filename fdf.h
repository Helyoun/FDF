#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define WIDTH 1920
#define HEIGHT 1080
#define LINE 50

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

typedef struct	mlx
{
	int	height;
	int	width;
	void	*init;
	void	*win;
}	s_mlx;

typedef struct	point
{
	float	x;
	float	y;
	float	z;
}	s_point;

typedef struct	map
{
	char	*row;
	short	size;
	struct	map	*next;
}	t_map;

//int     ft_strlen(char *s);
char    *get_next_line(int fd);
//void    *ft_free(char *line);
s_mlx	ft_open_window();
void	isometric(s_point a, s_point b, s_mlx mlx);
int	ft_strcmp(char *s1, char *s2);
//t_map	*ft_open_file(char *s, int *rows);
//t_map	*ft_make_map(int fd, int *rows);
//t_map	*ft_make_node(int fd, t_map **list);
//void	ft_free_list(t_map **list, void *ptr);
int	ft_isdigit(int c);
int	ft_isoprator(int c);


#endif
