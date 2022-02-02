NAME = fractol

LIST	= main.c mandelbrot.c color.c check_name.c julia.c tricon.c motion.c burning_ship.c

OBJ		= $(patsubst %.c,%.o,$(LIST))

CC = gcc

FLAGS = -Wall -Werror -Wextra

MLX = ./minilibx-linux/		#для macos ----> ./miniLibx/

MLX_LINK	= -L $(MLX) -l mlx -lXext -lX11 -lm		#для macos ----> -framework OpenGL -framework AppKit

all: $(NAME) $(OBJ)

%.o : %.c fractol.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MLX_LINK)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONNY : all clean fclean re