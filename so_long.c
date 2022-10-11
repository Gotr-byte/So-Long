/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:47:04 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/11 14:15:21 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	full_map_check(t_vars *vars)
{
	int	tmp_collect;
	int	num_exit;

	invalid_values(vars);
	check_nort_wall(vars);
	check_west_wall(vars);
	check_east_wall(vars);
	check_south_wall(vars);
	check_rect(vars);
	num_characters(vars);
	num_exits(vars);
	vars->num_collectables = num_collectables(vars);
	tmp_collect = check_path(vars, character_pos_x(), character_pos_y(), 0);
	num_exit = 0;
	num_exit = check_path_exit(vars, character_pos_x(), character_pos_y(), 0);
	if (tmp_collect != vars->num_collectables || num_exit != 1)
	{
		write (2, "Map error: no valid path\n", 26);
		exit (2);
	}
}

t_vars	*preloader(void)
{
	t_vars	*vars;

	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	vars->mlx = mlx_init();
	vars->m = map_reader();
	vars->n = map_reader();
	vars->o = map_reader();
	vars->map_x = map_width();
	vars->map_y = map_height();
	return (vars);
}

int	main(void)
{
	t_vars	*vars;

	vars = preloader();
	vars = img_load(vars);
	full_map_check(vars);
	vars->win = mlx_new_window(vars->mlx, \
	(vars->map_x + 3) * G, vars->map_y * G, "Blumenfeld");
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_loop_hook(vars->mlx, loop_hook, vars);
	mlx_loop(vars->mlx);
}
