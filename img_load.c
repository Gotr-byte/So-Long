/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:12:25 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/11 14:13:55 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_vars	*img_load_grass(t_vars	*vars)
{
	char	*grass_path;
	int		img_width;
	int		img_height;

	grass_path = "./xpm/grass.xpm";
	vars->grass = mlx_xpm_file_to_image(vars->mlx, \
	grass_path, &img_width, &img_height);
	return (vars);
}

t_vars	*img_load_exit(t_vars	*vars)
{
	char	*exit_path;
	int		img_width;
	int		img_height;

	exit_path = "./xpm/exit.xpm";
	vars->exit = mlx_xpm_file_to_image(vars->mlx, \
	exit_path, &img_width, &img_height);
	return (vars);
}

t_vars	*img_load_tree(t_vars	*vars)
{
	char	*tree_path;
	int		img_width;
	int		img_height;

	tree_path = "./xpm/tree.xpm";
	vars->tree = mlx_xpm_file_to_image(vars->mlx,\
	tree_path, &img_width, &img_height);
	return (vars);
}

t_vars	*img_load_tulecie(t_vars	*vars)
{
	char	*tulecie_path;
	int		img_width;
	int		img_height;

	tulecie_path = "./xpm/tulecie.xpm";
	vars->tulecie = mlx_xpm_file_to_image(vars->mlx, \
	tulecie_path, &img_width, &img_height);
	return (vars);
}

t_vars	*img_load(t_vars	*vars)
{
	char	*warlock_path = "./xpm/enemy_sprite_1.xpm";
	char	*warlock_path_un = "./xpm/enemy_sprite_6.xpm";
	int		img_width;
	int		img_height;

	vars = img_load_rock(vars);
	vars = img_load_grass(vars);
	vars = img_load_exit(vars);
	vars = img_load_tree(vars);
	vars = img_load_tulecie(vars);
	vars->warlock[0] = mlx_xpm_file_to_image(vars->mlx,\
	warlock_path, &img_width, &img_height);
	vars->warlock[1] = mlx_xpm_file_to_image(vars->mlx,\
	warlock_path_un, &img_width, &img_height);
	return (vars);
}