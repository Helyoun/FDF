#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define WIDTH 1000
#define HEIGHT 500
#define LINE 50

struct	mlx
{
	void	*mlx;
	void	*win;
	void	*img;
};

struct	point
{
	int	x;
	int	y;
	void	*color;
};

typedef struct	map
{
	char	*row;
	char	size;
	struct map	*next;
}	t_map;

int	ft_strlen(char *s);
int	ft_strcmp(char *s1, char *s2);
t_map	*ft_open_file(char *s, int *rows);
t_map	*ft_make_map(int fd, int *rows);
t_map	*ft_make_node(int fd, t_map **list);
int	ft_atoi(char *str, int *i);
void	ft_free_list(t_map **list, void *ptr);
int	ft_isdigit(int c);
int	ft_isoprator(int c);
char	*ft_strjoin(char *line, char c, int line_size, t_map **list);
char	*get_next_line(int fd, t_map **list);


#endif
