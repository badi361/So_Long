/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguzel <bguzel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:15:54 by bguzel            #+#    #+#             */
/*   Updated: 2024/01/17 18:01:28 by bguzel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./ft_libft/libft.h" 
# include "./FT_PRINTF/ft_printf.h"

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
	int		width;
	int		height;
	int		x_size;

}t_long;

void	file_check(int ac, char *av);
void	map_read_check(char *name, t_long *map);
void	map_read(char *name, t_long *map);
void	rectangle_cont(t_long *map);
void	location_and_cont(t_long *map);
void	location_and_cont2(t_long *map, int k, int i);
void	wall_cont(t_long *map);
void	undefined_char(t_long *map);
void	try_to_move(t_long *map);
void	try_to_move_2(t_long *map, int k, int i);
void	free_map(t_long *map);
void	mlx_put_img(t_long *map);
void	mlx_init_start(t_long *map);
void	mlx_get_image(t_long *map);
void	ft_img(t_long *map, void *img, int i, int k);
void	press_right(t_long *map);
void	press_down(t_long *map);
void	press_left(t_long *map);
void	press_up(t_long *map);
void	long_check(t_long *map);
void	last_line_check(t_long *map);
void	rectangle_cont_2(t_long *map, int i, int k, int l);
void	refresh_map(t_long *map);
int		c_control(t_long *map);
int		moving(int key, t_long *map);
int		ft_exit(t_long *map);

#endif
