/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:50:25 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/19 15:39:10 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*sr1;
	unsigned char	*sr2;

	i = ft_strlen(s1) - 4;
	if (i < 0)
		return (-1);
	j = 0;
	sr1 = (unsigned char *)s1;
	sr2 = (unsigned char *)s2;
	while ((sr1[i] != 0 || sr2[j] != 0) && i < n)
	{
		if (sr1[i] != sr2[j])
			return (sr1[i] - sr2[j]);
		i++;
		j++;
	}
	return (0);
}
