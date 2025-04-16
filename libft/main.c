#include "libft.h"
int	main (int c, char **v)
{
	t_map	*map;
	t_map	*tmp;
	s_mlx	mlx;
	map = openfile(c, v);
	mlx = ft_open_window();
	int	i;
	int	j = 0;
	int	s = 0;
	tmp = map;
	while (map != NULL)
	{
		i = 0;
		while (i < map->size)
		{
			isometric(i, j, map->row[i], mlx, 100);
			i++;
		}
		map = map->next;
		j++;
	}
	while(1);
}
