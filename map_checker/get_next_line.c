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

int	ft_countword(char *line)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (line[i] != 0)
	{
		if ((ft_isdigit(line[i]) == 1 || ft_isoperetor(line[i] == 1) && (line[i+1] == 32 || line[i+1] == '\n' || line[i+1] == 0))
			c++;
		i++;
	}
	return (c);
}

int	ft_atoi(char *str)
{
	static int	i;
	int	signe;
	int	result;

	signe = 1;
	result = 0;
	while ((str[i] < '0' || str[i] > '9') && (str[i] != '-' && str[i] != '+'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * signe);
}

int	*ft_split(char *line)
{
	int	i;
	int	countnumbers;
	int	*numbers_of_line;

	countnumbers = ft_countword(line);
	numbers_of_line = malloc(sizeof(int) * (countnumbers));
	if (numbers_of_line == NULL)
		return (NULL);
	i = 0;
	while (i < countnumbers)
	{
		numbers_of_line[i] = ft_atoi(line);
		i++;
	}
	printf("||%d||\n", countnumbers);
	return (numbers_of_line);
}

/*
void	*ft_free_map (char **map)
{
	int i;

	i = 0;
	while (map != NULL && map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
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
*/
int main ()
{
/*	char	**map;
	int	fd;
	int	i = 0 ;
	fd = open("txt", O_RDWR);

	map = ft_read_map(-1);
	while (map[i] != NULL)
	{
		printf("%s", map[i]);
		free(map[i]);
		i++;
	}
	free(map);*/

	int	*array = ft_split("    1kfgfasfakfaffa 12 aff fjfas ff-1 -12 1    i12iii 123 ====  -1 ojjll-12 //  -123   0");
	int	nbr = 0 ;
	while (array[nbr] != 0)
	{
		printf("%d\n", array[nbr]);
		nbr++;
	}
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
