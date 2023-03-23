#include "so_long.h"

void    map_read_check(char *name, t_long *map)
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
	//perror("a");
	while (i < map->line_size)
	{
		i++;
		map->map_line[i] = get_next_line(fd);
	}
	close(fd);
}
