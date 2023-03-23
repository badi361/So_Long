#include "so_long.h"

void	file_check(int ac, char *av)
{
	int		i;

	i = ft_strlen(av);
	if (ac != 2)
	{
		write(2, "ERROR\n", 6);
		exit(0);
	}
	if (av[i - 1] != 'r' && av[i - 2] != 'e' && av[i - 3] != 'b' && av[i - 4] != '.')
	{
		write(2, "ERROR\n", 6);
		exit(0);
	}
}

int main(int ac, char **av)
{
	t_long	*map;

	map = malloc(sizeof(t_long));
	file_check(ac, av[1]);
	map_read_check(av[1], map);
	map_read(av[1], map);
	rectangle_cont(map);
	undefined_char(map);
	try_to_move(map);
	map_read_check(av[1], map);
	map_read(av[1], map);
	mlx_init_start(map);
	mlx_put_img(map);
	mlx_loop(map->mlx_init);
	map->move = ft_itoa(map->p_move_count);
	mlx_string_put(map->mlx_init, map->mlx_win, 3, 3, 0x000000, map->move);
}