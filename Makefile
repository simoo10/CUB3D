FLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address
LIBC	= ar -rc
RM		= rm -f
NAME	= cub3d
SRC		= main.c\
			get_next_line.c\
			get_next_line_utils.c\
			libft_utils.c\
			map_check.c\

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:	fclean all