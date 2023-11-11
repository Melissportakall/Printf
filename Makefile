NAME		=	libftprintf.a
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf

SRC			=	ft_printf.c			\
				ft_printf_utils.c

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean 
	$(RM) $(NAME) $(LIBOBJ)

re: fclean all

.PHONY: all bonus clean fclean re