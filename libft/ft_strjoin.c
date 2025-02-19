/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 07:22:13 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/02/19 18:11:37 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *line, char c, int line_size, t_list **list)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (line_size + 1));
	if (str == NULL)
		ft_free_list(list, &line);
	i = 0;
	while (i < line_size - 1)
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i +1] = 0;
	free(line);
	return (str);
}
