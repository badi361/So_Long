/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baran <baran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:11:32 by bguzel            #+#    #+#             */
/*   Updated: 2023/03/28 17:38:44 by baran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_check(int ac, char *av)
{
	int		i;

	i = ft_strlen(av);
	if (ac != 2)
	{
		ft_putstr_fd("FILE_ERROR\n", 2);
		exit(0);
	}
	if (av[i - 1] != 'r' && av[i - 2] != 'e'
		&& av[i - 3] != 'b' && av[i - 4] != '.')
	{
		ft_putstr_fd("FILE_ERROR_2\n", 2);
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

void	long_check(t_long *map)
{
	if (map->line_size > 128 || map->x_size > 128)
	{
		ft_putstr_fd("Map Is So Long ERROR\n", 2);
		exit(0);
	}
}

void	last_line_check(t_long *map)
{
	if (map->map_line[map->line_size - 1] == NULL)
	{
		ft_putstr_fd("Last Line Null ERROR\n", 2);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_long	*map;

	map = malloc(sizeof(t_long));
	map->e_counter = 0;
	map->p_counter = 0;
	map->c_counter = 0;
	file_check(ac, av[1]);
	map_read_check(av[1], map);
	map_read(av[1], map);
	last_line_check(map);
	rectangle_cont(map);
	undefined_char(map);
	try_to_move(map);
	long_check(map);
	map_read_check(av[1], map);
	map_read(av[1], map);
	mlx_init_start(map);
	mlx_put_img(map);
	map->move = ft_itoa(map->p_move_count);
	mlx_string_put(map->mlx_init, map->mlx_win, 15, 15, 0x000000, map->move);
	mlx_hook(map->mlx_win, 2, 0, moving, map);
	mlx_hook(map->mlx_win, 17, 0, ft_exit, map);
	mlx_loop(map->mlx_init);
}
