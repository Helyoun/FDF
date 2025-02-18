CC =  cc

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_atoi.c	ft_isdigit.c	ft_isoprator.c	ft_split.c	ft_strjoin.c	ft_strnstr.c	git_next_line.c

SRCB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c	ft_lstmap_bonus.c

OBJ = ${SRC:.c=.o}

OBJS = ${SRCB:.c=.o}

NAME = libft.a

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

bonus : $(OBJS)
	
$(OBJS) : $(SRCB)
	$(CC) $(CFLAGS) $^ -c
	ar rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJ) $(OBJS)

fclean : clean
	rm -rf $(NAME)

re	: fclean all

.PHONY: re fclean clean bouns
