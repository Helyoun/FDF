/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 06:01:28 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/02/18 10:13:34 by hamel-yo         ###   ########.fr       */
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

int	*ft_split(int fd)
{
	int	i;
	int	j;
	char	*line;
	int	countnumbers;
	int	*numbers_of_line;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	countnumbers = ft_countword(str);
	numbers_of_line = malloc(sizeof(int) * (countnumbers));
	if (numbers_of_line == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < countnumbers)
	{
		numbers_of_line[i] = ft_atoi(str, &j);
		i++;
	}
	free(line);
	return (numbers_of_line);
}
