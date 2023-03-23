#include "so_long.h"

void	 try_to_move(t_long *map)
{
	int		result;

	try_to_move_2(map, map->p_y_loca, map->p_x_loca);
	result = c_control(map);
	if (result == 1)
	{
		write(2, "ERROR\n", 6);
		exit(0);
	}
	if (map->map_line[map->e_y_loca + 1][map->e_x_loca] != 'P' 
		&& map->map_line[map->e_y_loca - 1][map->e_x_loca] != 'P'
		&& map->map_line[map->e_y_loca][map->e_x_loca + 1] != 'P'
		&& map->map_line[map->e_y_loca][map->e_x_loca - 1] != 'P')
		{
			write(2, "ERROR\n", 6);
			exit(0);
		}
	free_map(map);
}

void	try_to_move_2(t_long *map, int k, int i)
{
	//perror("a");
	if (map->map_line[k][i + 1] == 'C' || map->map_line[k][i + 1] == '0')
	{
		map->map_line[k][i + 1] = 'P';
		//perror("b");
		try_to_move_2(map, k, i + 1);

	}
	if (map->map_line[k][i - 1] == 'C' || map->map_line[k][i - 1] == '0')
	{
		map->map_line[k][i - 1] = 'P';
		//perror("c");
		try_to_move_2(map, k, i - 1);
	}
	if (map->map_line[k + 1][i] == 'C' || map->map_line[k + 1][i] == '0')
	{
		map->map_line[k + 1][i] = 'P';
		//perror("d");
		try_to_move_2(map, k + 1, i);
	}
	if (map->map_line[k - 1][i] == 'C' || map->map_line[k - 1][i] == '0')
	{
		map->map_line[k - 1][i] = 'P';
		//perror("e");
		try_to_move_2(map, k - 1, i);
	}
}

int	c_control(t_long *map) // gezilen her yer P olduğu için C yi toplamış oluyoruz yani C olamaz
{
	int		i;
	int		k;

	k = 1;
	while (k < map->line_size - 1)
	{
		i = 0;
		while (map->map_line[k][i] != '\r')
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