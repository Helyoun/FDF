/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <hamel-yo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 03:10:43 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/03/17 21:14:48 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct list
{
	char	*array;
	char	size;
	struct list	*next;
}	t_list;

t_list	*ft_open_file(char *s, int *rows);
t_list	*ft_make_map(int fd, int *rows);
t_list	*ft_make_node(int fd, t_list **list);
int	ft_atoi(char *str, int *i);
void	ft_free_list(t_list **list, void *ptr);
int	ft_isdigit(int c);
int	ft_isoprator(int c);
char	*ft_strjoin(char *line, char c, int line_size, t_list **list);
char	*get_next_line(int fd, t_list **list);

#endif
