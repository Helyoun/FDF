#include "../fdf.h"

char	*ft_strjoin(char *line, char c, int line_size)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (line_size + 1));
	if (str == NULL)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (i < line_size - 1)
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1]= 0;
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	c;
	int		read_byte;
	int		line_size;

	if (fd < 0)
		return(NULL);
	line = NULL;
	line_size = 1;
	while (1)
	{
		read_byte = read(fd, &c, 1);
		if (read_byte == -1)
		{
			free(line);
			return (NULL);
		}
		else if (read_byte == 0)
			return (line);
		line = ft_strjoin(line, c, line_size);
		if (c == '\n' || line == NULL)
			break;
		line_size++;
	}
	return (line);
}

char	**ft_read_map(int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**tmp;
	char	**map;

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		tmp = malloc(sizeof(char *) * (i + 2));
		if (tmp == NULL)
			return (ft_free_map(map));
		j = 0;
		while (j < i)
		{
			tmp[j] = map[j];
			j++;
			free(map);
		}
		tmp[i] = line;
		map = tmp;
		i++;
	}
	map[i] = NULL;
	return (map);
}

/*
int	**ft_split (int fd)
{
	char	**lines;
	int	line_numbers;
	int	**map;

	lines = ft_

*/
int main ()
{
	char	**map;
	int	fd;
	int	i = 0 ;
	fd = open("txt", O_RDWR);

	map = ft_read_map(fd);
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}















































/*
int	**map(int fd)
{
	int	i;
	int	**map_numbers;
	int	numbers_on_line;
	char	*line;

	if (fd < 0)
		return (NULL);
	while ()
	{
	       	line = get_next_line(fd);
		ft_split(line);
	}

}*/
