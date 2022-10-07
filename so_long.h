/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:47:21 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/07 18:36:08 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# define GRID 48
# define NULL_VAL 1
# define TRUE 1

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*rock;
	void	*grass;
	void	*tree;
	void	*exit;
	void	*tulecie;
	void	*warlock[2];
	char	**m;
	char	**n;
	char	**o;
	int		num_collectables;
	int		map_x;
	int		map_y;
}t_vars;

// int		key_hook(int keycode, t_vars *mlx);
int		key_hook(int keycode, t_vars *mlx);
void	destructor(t_vars *mlx);
char	**map_reader(void);
int		map_height(void);
int		map_width(void);
void	liberator(char	**map, int map_height);
void	**map_refresh(t_vars mlx);
void	check_nort_wall(t_vars *vars);
void	check_west_wall(t_vars *vars);
void	check_east_wall(t_vars *vars);
void	check_south_wall(t_vars *vars);
void	check_rect(t_vars *vars);
void	num_characters(t_vars *vars);
void	num_exits(t_vars *vars);
int		num_collectables(t_vars *vars);
int		check_path(t_vars *vars, int x, int y, int num_collect_tmp);
int		check_path_exit(t_vars *vars, int x, int y, int num_exit);
int		character_pos_y(void);
int		character_pos_x(void);
void	invalid_values(t_vars *vars);
int		loop_hook(t_vars *mlx);
void	make_image(t_vars *mlx);
int		move_right(t_vars *mlx, int j, int i);
int		move_left(t_vars *mlx, int j, int i);
int		move_up(t_vars *mlx, int j, int i);
int		move_down(t_vars *mlx, int j, int i);
int		num_collect_hook(t_vars *vars);
#endif