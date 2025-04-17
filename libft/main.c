#include "libft.h"
int	main (int c, char **v)
{
	s_point	a;
	s_point	b;
	t_map	*map;
	t_map	*tmp;
	s_mlx	mlx;
	map = openfile(c, v);
	mlx = ft_open_window();
	int	i;
	int	j = 0;
	tmp = map;
	while (map != NULL)
	{
		i = 0;
		while (i + 1 < map->size)
		{
			a.x = (float)i;
			a.y = (float)j;
			a.z = (map->row)[i];
			b.x = (float)(i + 1);
			b.y = (float)j;
			b.z = (map->row)[i];
			isometric(a, b, mlx);
			i++;
		}
		map = map->next;
		j++;
	}
	while(1);
}
