FLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address
LIBC	= ar -rc
RM		= rm -f
NAME	= cub3d
MLX		= minilibx-linux
SRC		= main.c\
			libft_utils/get_next_line.c\
			libft_utils/get_next_line_utils.c\
			libft_utils/libft_utils.c\
			map_check.c\
			fill_map.c\
			textures_check.c\
			error.c\
			draw.c\

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)  -o $(NAME) $(OBJ) -L $(MLX) -lmlx -lm -lbsd -lX11 -lXext

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:	fclean all