CC =  cc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -lXext -lX11 -lm

SRC =	libft/ft_atoi.c	libft/ft_calloc.c	libft/ft_make_map.c	libft/ft_open_window.c	libft/ft_split.c	libft/ft_striteri.c	libft/ft_strncmp.c	libft/get_next_line_utils.c	libft/main.c	\
	libft/ft_bzero.c	libft/ft_free_map.c	libft/ft_memset.c	libft/ft_putstr_fd.c	libft/ft_strdup.c	libft/ft_strlen.c	libft/get_next_line.c	draw/isometric.c

OBJ =	$(SRC:.c=.o)

NAME = fdf

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS)

all : $(NAME)


clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re	: fclean all

.PHONY: re fclean clean
