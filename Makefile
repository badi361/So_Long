NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
FREAMS = -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a
LIBFT = ./libft/libft.a
GNL = ./getnextline/get_next_line.a
PRNTF = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME): *.o $(MLX) $(LIBFT) $(GNL) $(PRNTF)
	$(CC) $(FLAGS) -o $(NAME) *.o $(MLX) $(LIBFT) $(GNL) $(FREAMS) $(PRNTF)

*.o: *.c
	$(CC) $(FLAGS) -c *.c

$(MLX):
	@make -C ./mlx

$(LIBFT):
	@make -C ./libft

$(GNL):
	@make -C ./getnextline

$(PRNTF):
	@make -C ./ft_printf

clean:
	rm -f *.o
	@make clean -C ./mlx
	@make clean -C ./libft
	@make clean -C ./getnextline
	@make clean -C ./ft_printf

fclean: clean
	rm -f so_long
	@make fclean -C ./libft
	@make fclean -C ./getnextline
	@make fclean -C ./ft_printf

re:fclean all