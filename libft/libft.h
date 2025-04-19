/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamel-yo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:25:40 by hamel-yo          #+#    #+#             */
/*   Updated: 2025/04/19 17:12:23 by hamel-yo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../fdf.h"

# define SHORT_MAX 32767
# define SHORT_MIN -32768

# define BUFFER_SIZE 1337

void				ft_free_map(t_map **map);
t_map				*openfile(int c, char **v);
t_map				*makemap(int fd);
t_map				*makenode(char *line);
int					ft_count_word(char *s, char c);
short				*ft_makerow(char **sl, short size);
void				*ft_free(void **strs, int i);
char				*get_next_line(int fd);
void				*gnlfree(char *line, int i);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s);
int					ft_atoi(const char *str);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
void				ft_putstr_fd(char *s, int fd);

#endif
