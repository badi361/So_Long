#include "so_long.h"

void	press_up(t_long *map)
{
	if (map->map_line[map->p_y_loca / 64 - 1][map->p_x_loca / 64] != '1')
	{
		if (map->map_line[map->p_y_loca / 64 - 1][map->p_x_loca / 64] == 'C')
			map->c_counter--;
		if (map->map_line[map->p_y_loca / 64 - 1][map->p_x_loca / 64] == 'E')
		{
			if (map->c_counter == 0)
				exit(0);
		}
		if (map->map_line[map->p_y_loca / 64 - 1][map->p_x_loca / 64] != 'E')
		{
			map->map_line[map->p_y_loca / 64][map->p_x_loca / 64] = '0';
			map->map_line[map->p_y_loca / 64 - 1][map->p_x_loca / 64] = 'P';
			map->p_y_loca = map->p_y_loca - 64;
			map->p_move_count++;
			ft_printf("move count : %d\n", map->p_move_count);
		}
	mlx_clear_window(map->mlx_init, map->mlx_win);
	map->move = ft_itoa(map->p_move_count);
	mlx_put_img(map); 
	mlx_string_put(map->mlx_init, map->mlx_win, 15, 15, 0x000000, map->move);
	free(map->move);
	}
}

void	press_left(t_long *map)
{
	if (map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 - 1] != '1')
	{
		if (map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 - 1] == 'C')
			map->c_counter--;
		if (map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 - 1] == 'E')
		{
			if (map->c_counter == 0)
				exit(0);
		}
		if (map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 - 1] != 'E')
		{
			map->map_line[map->p_y_loca / 64][map->p_x_loca / 64] = '0';
			map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 - 1] = 'P';
			map->p_x_loca = map->p_x_loca - 64;
			map->p_move_count++;
			ft_printf("move count : %d\n", map->p_move_count);
		}
	mlx_clear_window(map->mlx_init, map->mlx_win);
	map->move = ft_itoa(map->p_move_count);
	mlx_put_img(map); 
	mlx_string_put(map->mlx_init, map->mlx_win, 15, 15, 0x000000, map->move);
	free(map->move);
	}
}

void	press_down(t_long *map)
{
	if (map->map_line[map->p_y_loca / 64 + 1][map->p_x_loca / 64] != '1')
	{
		if (map->map_line[map->p_y_loca / 64 + 1][map->p_x_loca / 64] == 'C')
			map->c_counter--;
		if (map->map_line[map->p_y_loca / 64 + 1][map->p_x_loca / 64] == 'E')
		{
			if (map->c_counter == 0)
				exit(0);
		}
		if (map->map_line[map->p_y_loca / 64 + 1][map->p_x_loca / 64] != 'E')
		{
			map->map_line[map->p_y_loca / 64][map->p_x_loca / 64] = '0';
			map->map_line[map->p_y_loca / 64 + 1][map->p_x_loca / 64] = 'P';
			map->p_y_loca = map->p_y_loca + 64;
			map->p_move_count++;
			ft_printf("move count : %d\n", map->p_move_count);
		}
	mlx_clear_window(map->mlx_init, map->mlx_win);
	map->move = ft_itoa(map->p_move_count);
	mlx_put_img(map); 
	mlx_string_put(map->mlx_init, map->mlx_win, 15, 15, 0x000000, map->move);
	free(map->move);
	}
}

void	press_right(t_long *map)
{
	if (map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 + 1] != '1')
	{
		if (map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 + 1] == 'C')
			map->c_counter--;
		if (map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 + 1] == 'E')
		{
			if (map->c_counter == 0)
				exit(0);
		}
		if (map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 + 1] != 'E')
		{
			map->map_line[map->p_y_loca / 64][map->p_x_loca / 64] = '0';
			map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 + 1] = 'P';
			map->p_x_loca = map->p_x_loca + 64;
			map->p_move_count++;
			ft_printf("move count : %d\n", map->p_move_count);
		}
	mlx_clear_window(map->mlx_init, map->mlx_win);
	map->move = ft_itoa(map->p_move_count);
	mlx_put_img(map); 
	mlx_string_put(map->mlx_init, map->mlx_win, 15, 15, 0x000000, map->move);
	free(map->move);
	}
}
int	 moving(int	key, t_long *map)
{
	/*map->p_x_loca = map->p_x_loca * 64;
	map->p_y_loca = map->p_y_loca * 64;
	printf("%d\n", map->p_y_loca);
	printf("%d\n", map->p_x_loca);*/
	if (key == 53)
	{
		mlx_destroy_window(map->mlx_init, map->mlx_win);
		exit(0);
	}
	else if (key == 13)
		press_up(map);
	else if (key == 0)
		press_left(map);
	else if (key == 1)
		press_down(map);
	else if (key == 2)
		press_right(map);   
	return (0);
}