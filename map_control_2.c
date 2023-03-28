/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:19:49 by bguzel            #+#    #+#             */
/*   Updated: 2023/03/28 04:40:39 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	try_to_move(t_long *map)
{
	int		result;

	try_to_move_2(map, map->p_y_loca / 64, map->p_x_loca / 64);
	result = c_control(map);
	if (result == 1)
	{
		ft_putstr_fd("MOVE_ERROR\n", 2);
		exit(0);
	}
	if (map->map_line[map->e_y_loca / 64 + 1][map->e_x_loca / 64] != 'P'
		&& map->map_line[map->e_y_loca / 64 - 1][map->e_x_loca / 64] != 'P'
		&& map->map_line[map->e_y_loca / 64][map->e_x_loca / 64 + 1] != 'P'
		&& map->map_line[map->e_y_loca / 64][map->e_x_loca / 64 - 1] != 'P')
	{
		ft_putstr_fd("MOVE_ERROR_2\n", 2);
		exit(0);
	}
	free_map(map);
}

void	try_to_move_2(t_long *map, int k, int i)
{
	if (map->map_line[k][i + 1] == 'C' || map->map_line[k][i + 1] == '0')
	{
		map->map_line[k][i + 1] = 'P';
		try_to_move_2(map, k, i + 1);
	}
	if (map->map_line[k][i - 1] == 'C' || map->map_line[k][i - 1] == '0')
	{
		map->map_line[k][i - 1] = 'P';
		try_to_move_2(map, k, i - 1);
	}
	if (map->map_line[k + 1][i] == 'C' || map->map_line[k + 1][i] == '0')
	{
		map->map_line[k + 1][i] = 'P';
		try_to_move_2(map, k + 1, i);
	}
	if (map->map_line[k - 1][i] == 'C' || map->map_line[k - 1][i] == '0')
	{
		map->map_line[k - 1][i] = 'P';
		try_to_move_2(map, k - 1, i);
	}
}

int	c_control(t_long *map)
{
	int		i;
	int		k;

	k = 1;
	while (k < map->line_size - 1)
	{
		i = 0;
		while (map->map_line[k][i] != '\r' && map->map_line[k][i] != '\n')
		{
			if (map->map_line[k][i] == 'C')
				return (1);
		i++;
		}
	k++;
	}
	return (0);
}

void	free_map(t_long *map)
{
	int		i;

	i = 0;
	while (i < map->line_size)
	{
		free(map->map_line[i]);
		i++;
	}
	free(map->map_line);
}
