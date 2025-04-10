/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:32:37 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/09 22:36:07 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_free_list(t_map **list, void *ptr)
{
	void	*tmp;

	while (*list != NULL)
	{
		tmp = (*list)->next;
		free ((*list)->row);
		free (*list);
		*list = tmp;
	}
	free(ptr);
	exit (0);
}
