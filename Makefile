NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
FREAMS = -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a
LIBFT = ./libft/libft.a
GNL = ./getnextline/get_next_line.a

all: $(NAME)

$(NAME): *.o $(MLX) $(LIBFT) $(GNL)
	$(CC) $(FLAGS) -o $(NAME) *.o $(MLX) $(LIBFT) $(GNL) $(FREAMS)

*.o: *.c
	$(CC) $(FLAGS) -c *.c

$(MLX):
	@make -C ./mlx

$(LIBFT):
	@make -C ./libft

$(GNL):
	@make -C ./getnextline

clean:
	rm -f *.o
	@make clean -C ./mlx
	@make clean -C ./libft
	@make clean -C ./getnextline

fclean: clean
	rm -f so_long
	@make fclean -C ./libft
	@make fclean -C ./getnextline

re:fclean all