/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_ctrl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:16:41 by bguzel            #+#    #+#             */
/*   Updated: 2023/03/28 04:29:44 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read_check(char *name, t_long *map)
{
	int		fd;
	int		size;
	char	a;

	size = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		exit(0);
	while (read(fd, &a, 1))
	{
		if (a == '\n')
			size = size + 1;
	}
	size++;
	map->line_size = size;
	close(fd);
	map->map_line = malloc(sizeof(char *) * size + 1);
	map->map_line[size + 1] = NULL;
}

void	map_read(char *name, t_long *map)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		exit(0);
	map->map_line[i] = get_next_line(fd);
	if (map->map_line[i] == NULL)
	{
		ft_putstr_fd("Map Is Empty\n", 2);
		exit(0);
	}
	while (i < map->line_size)
	{
		i++;
		map->map_line[i] = get_next_line(fd);
	}
	close(fd);
}

void	rectangle_cont_2(t_long *map, int i, int k, int l)
{
	if (k + 1 == map->line_size - 1)
	{
		while (map->map_line[k + 1][l] != '\0')
			l++;
	}
	if (i != l)
	{
		ft_putstr_fd("RECTANGLE_ERROR\n", 2);
		exit(0);
	}
}
