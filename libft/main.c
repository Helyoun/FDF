#include "libft.h"

int main ()
{
	int	fd = open("txt", O_RDWR);
	t_list	*map = ft_make_map(fd);
	int 	l;


	if (map == NULL)
		printf("fuck this shit");
	while (map != NULL)
	{
		l = 0;
		while (map->array[l] != 0)
		{
			printf("%d\t", map[i][l]);
			l++;
		}
		printf("\n");
	}
}
