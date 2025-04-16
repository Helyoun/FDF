/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 06:01:28 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/15 06:33:43 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char *s, char c)
{
	int	w;

	w = 0;
	while (*s != 0)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
			w++;
		s++ ;
	}
	return (w);
}

char	*ft_makestr(char **s, char c)
{
	size_t	i;
	char	*str;

	i = 0 ;
	while (s[0][i] != c && s[0][i] != 0)
		i++;
	str = (char *)ft_calloc((i + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (**s != 0 && **s != c)
	{
		str[i] = **s;
		i++;
		(*s)++;
	}
	return (str);
}

void	*ft_free(void **strs, int i)
{
	char **s;

	s = (char **)strs;
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		w;
	int		i;
	char	**strs;

	if (s == NULL)
		return (NULL);
	w = ft_count_word((char *)s, c);
	strs = (char **) ft_calloc((w + 1), sizeof(char *));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (*s != 0 && i < w)
	{
		if (*s != c)
		{
			strs[i] = ft_makestr((char **)&s, c);
			if (strs[i] == NULL)
				return (ft_free((void *)strs, (int)i));
			i++;
		}
		if (*s != 0)
			s++;
	}
	return (strs);
}
