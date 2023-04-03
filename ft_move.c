/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:20:38 by bguzel            #+#    #+#             */
/*   Updated: 2023/04/03 15:10:37 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			{
				map->p_move_count++;
				ft_printf("move count : %d\n", map->p_move_count);
				exit(0);
			}
		}
		if (map->map_line[map->p_y_loca / 64 - 1][map->p_x_loca / 64] != 'E')
		{
			map->map_line[map->p_y_loca / 64][map->p_x_loca / 64] = '0';
			map->map_line[map->p_y_loca / 64 - 1][map->p_x_loca / 64] = 'P';
			map->p_y_loca = map->p_y_loca - 64;
			map->p_move_count++;
			ft_printf("move count : %d\n", map->p_move_count);
		}
		refresh_map(map);
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
			{
				map->p_move_count++;
				ft_printf("move count : %d\n", map->p_move_count);
				exit(0);
			}
		}
		if (map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 - 1] != 'E')
		{
			map->map_line[map->p_y_loca / 64][map->p_x_loca / 64] = '0';
			map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 - 1] = 'P';
			map->p_x_loca = map->p_x_loca - 64;
			map->p_move_count++;
			ft_printf("move count : %d\n", map->p_move_count);
		}
		refresh_map(map);
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
			{
				map->p_move_count++;
				ft_printf("move count : %d\n", map->p_move_count);
				exit(0);
			}
		}
		if (map->map_line[map->p_y_loca / 64 + 1][map->p_x_loca / 64] != 'E')
		{
			map->map_line[map->p_y_loca / 64][map->p_x_loca / 64] = '0';
			map->map_line[map->p_y_loca / 64 + 1][map->p_x_loca / 64] = 'P';
			map->p_y_loca = map->p_y_loca + 64;
			map->p_move_count++;
			ft_printf("move count : %d\n", map->p_move_count);
		}
		refresh_map(map);
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
			{
				map->p_move_count++;
				ft_printf("move count : %d\n", map->p_move_count);
				exit(0);
			}
		}
		if (map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 + 1] != 'E')
		{
			map->map_line[map->p_y_loca / 64][map->p_x_loca / 64] = '0';
			map->map_line[map->p_y_loca / 64][map->p_x_loca / 64 + 1] = 'P';
			map->p_x_loca = map->p_x_loca + 64;
			map->p_move_count++;
			ft_printf("move count : %d\n", map->p_move_count);
		}
		refresh_map(map);
	}
}

int	moving(int key, t_long *map)
{
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
