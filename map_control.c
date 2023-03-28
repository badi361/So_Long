/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:18:22 by bguzel            #+#    #+#             */
/*   Updated: 2023/03/28 04:40:31 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rectangle_cont(t_long *map)
{
	int		i;
	int		k;
	int		l;

	k = 0;
	while (k < map->line_size && k + 1 != map->line_size)
	{
		i = 0;
		l = 0;
		while (map->map_line[k][i] != '\n' && map->map_line[k][i] != '\r')
			i++;
		while (map->map_line[k + 1][l] != '\n' &&
			map->map_line[k + 1][l] != '\r' && k + 1 != map->line_size - 1)
			l++;
		rectangle_cont_2(map, i, k, l);
		k++;
	}
	map->x_size = i;
	location_and_cont(map);
}

void	location_and_cont(t_long *map)
{
	int		i;
	int		k;

	k = 0;
	while (k < map->line_size)
	{
		i = 0;
		while (map->map_line[k][i] != '\n')
		{
			if (map->map_line[k][i] == '\0')
				break ;
			location_and_cont2(map, k, i);
			i++;
		}
	k++;
	}
	if (map->p_counter != 1 || map->e_counter != 1 || map->c_counter < 1)
	{
		ft_putstr_fd("ARG_ERROR\n", 2);
		exit(0);
	}
	wall_cont(map);
}

void	location_and_cont2(t_long *map, int k, int i)
{
	if (map->map_line[k][i] == 'P')
	{
		map->p_x_loca = i * 64;
		map->p_y_loca = k * 64;
		map->p_counter++;
	}
	if (map->map_line[k][i] == 'E')
	{
		map->e_x_loca = i * 64;
		map->e_y_loca = k * 64;
		map->e_counter++;
	}
	if (map->map_line[k][i] == 'C')
		map->c_counter++;
}

void	wall_cont(t_long *map)
{
	int		i;
	int		k;

	i = 0;
	k = 1;
	while ((map->map_line[0][i] != '\r' && map->map_line[0][i] != '\n')
		|| map->map_line[map->line_size - 1][i] != '\0')
	{
		if (map->map_line[0][i] != '1' ||
			map->map_line[map->line_size - 1][i] != '1')
		{
			ft_putstr_fd("WALL_ERROR\n", 2);
			exit(0);
		}
	i++;
	}
	while (k < map->line_size - 1)
	{
		if (map->map_line[k][0] != '1' || map->map_line[k][i - 1] != '1')
		{
			ft_putstr_fd("WALL_ERROR_2\n", 2);
			exit(0);
		}
	k++;
	}
}

void	undefined_char(t_long *map)
{
	int		i;
	int		k;

	k = 0;
	while (k < map->line_size - 1)
	{
		i = 0;
		while (map->map_line[k][i] != '\r' && map->map_line[k][i] != '\n')
		{
			if (map->map_line[k][i] == '0' || map->map_line[k][i] == '1'
				|| map->map_line[k][i] == 'C' || map->map_line[k][i] == 'E'
					|| map->map_line[k][i] == 'P')
				i++;
			else
			{
				ft_putstr_fd("UNDEFINED_ERROR\n", 2);
				exit(0);
			}
		}
	k++;
	}
}
