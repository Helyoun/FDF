/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 06:11:22 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/18 16:47:53 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_makerow(char **sl, short size)
{
	char	*row;
	int	i;

	row = ft_calloc (sizeof(char) , size);
	if (row == NULL)
		return (row);
	i = 0;
	while (i < size)
	{
		row[i] = ft_atoi(sl[i]);
		i++;
	}
	ft_free((void *)sl, size);
	return (row);
}

t_map	*makenode(char *line)
{
	t_map	*map;
	char	**split;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->size = ft_count_word(line, ' ');
	split = ft_split(line, ' ');
	if (split == NULL)
		return (NULL);
	map->row = ft_makerow(split, map->size);
	map->next = NULL;
	return (map);
}

t_map	*makemap(int fd)
{
	t_map	*tmp;
	t_map	*map;
	int	i;
	char	*line;

	map = NULL;
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (map == NULL)
			tmp = makenode(line);
		else
			tmp->next = makenode(line);
		if (i == 0)
			map = tmp ;
		else
			tmp = tmp->next;
		i++;
		free(line);
	}
	return (map);
}

t_map *openfile(int c, char **v)
{
	int	fd;
	if (c != 2)
		return (NULL);
	fd = open(v[1], O_RDWR);
	return (makemap(fd));
}
