/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:28:16 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/02/18 01:40:33 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	c;
	int		read_byte;
	int		line_size;

	if (fd < 0)
		return (NULL);
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
			break ;
		line_size++;
	}
	return (line);
}
