#include "libft.h"

int main (int ac, char **av)
{
	int	fd = open(av[1], O_RDWR);
	t_list	*map = ft_make_map(fd);
	t_list	*save ;
	save = map;
	int 	l;

	printf("%d\n", sizeof(t_list));
	if (map == NULL)
		printf("fuck this shit");
	while (map != NULL)
	{
		l = 0;
		while (l < map->size)
		{
			printf("%d ", map->array[l]);
			if (map->array[l] < 9)
				printf(" ");
			l++;
		}
		printf("\n");
		map = map->next;
	}
	ft_free_list(&save, NULL);
}
