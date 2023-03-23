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

int	ft_exit(t_long *map)
{
	mlx_destroy_image(map->mlx_init, map->b_img);
	mlx_destroy_image(map->mlx_init, map->c_img);
	mlx_destroy_image(map->mlx_init, map->e_img);
	mlx_destroy_image(map->mlx_init, map->p_img);
	mlx_destroy_image(map->mlx_init, map->w_img);
	mlx_clear_window(map->mlx_init, map->mlx_win);
	free_map(map);
	exit(0);
	return (0);
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
	map->move = ft_itoa(map->p_move_count);
	mlx_string_put(map->mlx_init, map->mlx_win, 15, 15, 0x000000, map->move);
	mlx_hook(map->mlx_win, 17, 0, ft_exit, map);
	mlx_hook(map->mlx_win, 2, 0, moving, map);
	mlx_loop(map->mlx_init);
}