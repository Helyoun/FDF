/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 06:01:28 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/02/22 23:19:00 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(int c, int s)
{
	if (ft_isdigit(c) == 1 || ft_isoprator(c) == 1)
	{
		if (s == 32 || s == '\n' || s == 0)
			return (1);
	}
	return (0);
}

int	ft_countword(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != 0)
	{
		if (ft_check(str[i], str[i +1]) == 1)
			c++;
		i++;
	}
	return (c);
}

int	*ft_split(char *line, int *countnumbers, t_list **list)
{
	int	i;
	int	j;
	int	*numbers_of_line;

	*countnumbers = ft_countword(line);
	if (*countnumbers == 0)
	{
		free(line);
		return (NULL);
	}
	numbers_of_line = malloc(sizeof(int) * (*countnumbers));
	if (numbers_of_line == NULL)
		ft_free_list(list, line);
	i = 0;
	j = 0;
	while (i < *countnumbers)
	{
		numbers_of_line[i] = ft_atoi(line, &j);
		i++;
	}
	free(line);
	return (numbers_of_line);
}

t_list	*ft_make_node(int fd, t_list **list)
{
	t_list	*node;
	char	*line;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		ft_free_list(list, NULL);
	line = get_next_line(fd, list);
	if (line == NULL)
	{
		free(node);
		return (NULL);
	}
	node->array = ft_split(line, &node->size, list);
	if (node->array == NULL)
	{
		free (node);
		return (NULL);
	}
	node->next = NULL;
	return(node);
}
