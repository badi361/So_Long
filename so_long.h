#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "getnextline/get_next_line.h"
# include "libft/libft.h" 

typedef struct s_long
{
	void	*mlx_init;
	void	*mlx_win;
	void	*w_img;
	void	*e_img;
	void	*c_img;
	void	*b_img;
	void	*p_img;
	char	**map_line;
	char	*move;
	int		line_size;
	int		p_x_loca;
	int		p_y_loca;
	int		e_x_loca;
	int		e_y_loca;
	int		p_counter;
	int		e_counter;
	int		c_counter;
	int		p_move_count;
	int		y_size;
	int 	width;
	int 	height;
	

}t_long;

void	file_check(int ac, char *av);
void    map_read_check(char *name, t_long *map);
void	map_read(char *name, t_long *map);
void	rectangle_cont(t_long *map);
void	location_and_cont(t_long *map);
void	location_and_cont2(t_long *map, int k, int i);
void	wall_cont(t_long *map);
void	undefined_char(t_long *map);
void	try_to_move(t_long *map);
void	try_to_move_2(t_long *map, int k, int i);
void	free_map(t_long *map);
int		c_control(t_long *map);
void	mlx_put_img(t_long *map);
void	mlx_init_start(t_long *map);
void	mlx_get_image(t_long *map);
void	ft_img(t_long *map, void *img, int i, int k);

#endif
