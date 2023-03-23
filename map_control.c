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
		while (map->map_line[k][i] != '\n')
			i++;
		while (map->map_line[k + 1][l] != '\n' && k + 1 != map->line_size - 1)
			l++;
		if (k + 1 == map->line_size - 1)
		{
			while (map->map_line[k + 1][l] != '\0')
				l++;
		i--; // \n ve \0 a kadar git dediğim zaman son satırda indexler aynı olmuyordu sebebini anlamadım fakat i yi 1 azaltınca düzeldi (sebebi \n den önce gizli \r olması)
		}
		if (i != l)
		{
			write(2, "ERROR\n", 6);
			exit(0);
		}
		k++;
	}
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
			location_and_cont2(map, k, i);
			if (map->map_line[k][i] == '\0')
				break ;
			i++;
		}
	//printf("%d\n", i);
	k++;
	}
	//printf("%c\n", map->map_line[0][34]);
	if (map->p_counter != 1 || map->e_counter != 1)
	{
		write(2, "ERROR\n", 6);
		exit(0); 
	}
	wall_cont(map);
}

void	location_and_cont2(t_long *map, int k, int i)
{
	if (map->map_line[k][i] == 'P')
	{
		map->p_x_loca = i;
		map->p_y_loca = k;
		map->p_counter++;
	}
	if (map->map_line[k][i] == 'E')
	{
		map->e_x_loca = i;
		map->e_y_loca = k;
		map->e_counter++;
	}
	if (map->map_line[k][i] == 'C')
		map->c_counter++;
}

void	wall_cont(t_long *map)	//normalde alt satıra geçmek için \n kullanılır fakat bazı dosya biçimlerinde \r\n şeklinde kullanılabilir. burda da bu şekiled kullanılmış.
{
	int		i;
	int		k;

	i = 0;
	k = 1;
	//printf("%d\n", map->map_line[0][34] - 1);
	while (map->map_line[0][i] != '\r' || map->map_line[map->line_size - 1][i] != '\0')
	{
		if (map->map_line[0][i] != '1' || map->map_line[map->line_size - 1][i] != '1')
		{
			write(2, "ERROR\n", 6);
			exit(0);
		}
	i++;
	}
	while (k < map->line_size - 1)
	{
		if (map->map_line[k][0] != '1' || map->map_line[k][i - 1] != '1')
		{
			write(2, "ERROR\n", 6);
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
		while (map->map_line[k][i] != '\r')
		{
			if (map->map_line[k][i] == '0' || map->map_line[k][i] == '1' || map->map_line[k][i] == 'C' || map->map_line[k][i] == 'E' || map->map_line[k][i] == 'P')
				i++;
			else
			{
				write(2, "ERROR\n", 6);
				exit(0);
			}
		}
	k++;
	}
}