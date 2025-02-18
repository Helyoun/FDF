#include "libft.h"

int main ()
{
	int	fd = open("txt", O_RDWR);
	int	**map = ft_make_map(fd);
	int i = 0;
	int 	l;
	while (map[i] != NULL)
	{
		l = 0;
		while (map[i][l] < 10)
		{
			printf("%d\t", map[i][l]);
			l++;
		}
		printf("\n");
		i++;
	}
}
