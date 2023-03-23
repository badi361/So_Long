#include "so_long.h"

void	press_up(t_long *map, int x, int y)
{
	if (map->map_line[y - 1][x] != '1')
	{
		if (map->map_line[y - 1][x] == 'C')
			map->c_counter--;
		if (map->map_line[y - 1][x] == 'E')
		{
			if (map->c_counter == 0)
				exit(0);
		}
		if (map->map_line[y - 1][x] != 'E')
		{
			map->map_line[y][x] = '0';
			map->map_line[y - 1][x] = 'P';
		}
	mlx_clear_window(map->mlx_init, map->mlx_win);
	map->p_counter++;
	map->move = ft_itoa(map->p_counter);
	mlx_put_img(map); 
	mlx_string_put(map->mlx_init, map->mlx_win, 15, 15, 0x000000, map->move);
	map->p_y_loca--;
	free(map->move);
	}
}

void	press_left(t_long *map, int x, int y)
{
	if (map->map_line[y][x - 1] != '1')
	{
		if (map->map_line[y][x - 1] == 'C')
			map->c_counter--;
		if (map->map_line[y][x - 1] == 'E')
		{
			if (map->c_counter == 0)
				exit(0);
		}
		if (map->map_line[y][x - 1] != 'E')
		{
			map->map_line[y][x] = '0';
			map->map_line[y][x - 1] = 'P';
		}
	mlx_clear_window(map->mlx_init, map->mlx_win);
	map->p_counter++;
	map->move = ft_itoa(map->p_counter);
	mlx_put_img(map); 
	mlx_string_put(map->mlx_init, map->mlx_win, 15, 15, 0x000000, map->move);
	map->p_x_loca--;
	free(map->move);
	}
}

void	press_down(t_long *map, int x, int y)
{
	if (map->map_line[y + 1][x] != '1')
	{
		if (map->map_line[y + 1][x] == 'C')
			map->c_counter--;
		if (map->map_line[y + 1][x] == 'E')
		{
			if (map->c_counter == 0)
				exit(0);
		}
		if (map->map_line[y + 1][x] != 'E')
		{
			map->map_line[y][x] = '0';
			map->map_line[y + 1][x] = 'P';
		}
	mlx_clear_window(map->mlx_init, map->mlx_win);
	map->p_counter++;
	map->move = ft_itoa(map->p_counter);
	mlx_put_img(map); 
	mlx_string_put(map->mlx_init, map->mlx_win, 15, 15, 0x000000, map->move);
	map->p_y_loca++;
	free(map->move);
	}
}

void	press_right(t_long *map, int x, int y)
{
	if (map->map_line[y][x + 1] != '1')
	{
		if (map->map_line[y][x + 1] == 'C')
			map->c_counter--;
		if (map->map_line[y][x + 1] == 'E')
		{
			if (map->c_counter == 0)
				exit(0);
		}
		if (map->map_line[y][x + 1] != 'E')
		{
			map->map_line[y][x] = '0';
			map->map_line[y][x + 1] = 'P';
		}
	mlx_clear_window(map->mlx_init, map->mlx_win);
	map->p_counter++;
	map->move = ft_itoa(map->p_counter);
	mlx_put_img(map); 
	mlx_string_put(map->mlx_init, map->mlx_win, 15, 15, 0x000000, map->move);
	map->p_x_loca++;
	free(map->move);
	}
}
int	moving(int	key, t_long *map)
{
	int		x;
	int		y;

	x = map->p_x_loca;
	y = map->p_y_loca;
	if (key == 53)
	{
		mlx_destroy_window(map->mlx_init, map->mlx_win);
		exit(0);
	}
	else if (key == 13)
		press_up(map, x, y);
	else if (key == 0)
		press_left(map, x, y);
	else if (key == 1)
		press_down(map, x, y);
	else if (key == 2)
		press_right(map, x, y);
	return (0);
}