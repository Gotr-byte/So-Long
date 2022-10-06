/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:47:04 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/06 19:53:44 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"


//need movement hookers
// we should free the whole array it has some leaks

// void init_assets(t_vars vars)
// {
// }

void	full_map_check(t_vars vars)
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
	vars.num_collectables = num_collectables(vars);
	tmp_collect = check_path(vars, character_pos_x(), character_pos_y(), 0);
	num_exit = 0;
	liberator(vars.m, vars.map_y);
	vars.m = map_reader();
	num_exit = check_path_exit(vars, character_pos_x(), character_pos_y(), 0);
	if (tmp_collect != vars.num_collectables || num_exit != 1)
	{
		write (2, "Map error: no valid path\n", 26);
		exit (2);
	}
	liberator(vars.m, vars.map_y);
}

t_vars	loader(void)
{
	t_vars	vars;
	char	*grass_path = "./xpm/grass.xpm";
	char	*tree_path = "./xpm/tree.xpm";
	char	*tulecie_path = "./xpm/tulecie.xpm";
	char	*exit_path = "./xpm/exit.xpm";
	char	*rock_path = "./xpm/rock.xpm";
	int		img_width;
	int		img_height;

	vars.mlx = mlx_init();
	vars.map_x = map_width();
	vars.map_y = map_height();
	vars.win = mlx_new_window(vars.mlx, vars.map_x * GRID, vars.map_y * GRID, "Blumenfeld");
	vars.rock = mlx_xpm_file_to_image(vars.mlx, rock_path, &img_width, &img_height);
	vars.exit = mlx_xpm_file_to_image(vars.mlx, exit_path, &img_width, &img_height);
	vars.grass = mlx_xpm_file_to_image(vars.mlx, grass_path, &img_width, &img_height);
	vars.tree = mlx_xpm_file_to_image(vars.mlx, tree_path, &img_width, &img_height);
	vars.tulecie = mlx_xpm_file_to_image(vars.mlx, tulecie_path, &img_width, &img_height);
	vars.rock = mlx_xpm_file_to_image(vars.mlx, rock_path, &img_width, &img_height);
	vars.grass = mlx_xpm_file_to_image(vars.mlx, grass_path, &img_width, &img_height);
	vars.m = map_reader();
	return (vars);
}

int	main(void)
{
	t_vars	vars;

	vars = loader();
	full_map_check(vars);
	vars = loader();
	mlx_key_hook(vars.win, key_hook, &vars);
	liberator(vars.m, vars.map_y);
	mlx_loop(vars.mlx);
}
