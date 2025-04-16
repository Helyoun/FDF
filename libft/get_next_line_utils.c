/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:20:55 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/16 10:33:22 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*gnlfree(char *line, int i)
{
	free (line);
	if (i == -1)
	{
		ft_putstr_fd("|| ERROR IN READING MAP ||\n", 2);
		return ((void *)-1);
	}
	return (NULL);
}
