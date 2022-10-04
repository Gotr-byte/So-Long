/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:47:21 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/04 11:19:37 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include <stdio.h>
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
	char		**map;
	int		map_x;
	int		map_y;
}t_vars;

int		key_hook(int keycode, t_vars *mlx);
void	destructor(t_vars *mlx);
char	**map_reader();
int		map_height(void);
int		map_width(void);
void	liberator(char	**map, int map_height);
char	**map_refresh(void);
#endif