/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:47:04 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/04 11:19:05 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

//need a function that counts the number of lines in the file
//need a map checker
//need movement hookers
// we should free the whole array it has some leaks
int	main(void)
{
	t_vars	vars;
	char	*grass_path = "./xpm/grass.xpm";
	char	*tree_path = "./xpm/tree.xpm";
	char	*tulecie_path = "./xpm/tulecie.xpm";
	char	*exit_path = "./xpm/exit.xpm";
	char	*rock_path = "./xpm/rock.xpm";
	int		img_width;
	int		img_height;
	int		i;
	int		j;
	int		x;
	int		y;

	vars.map_y = map_height();
	vars.map_x = map_width();
	vars.map = map_reader();
	y = 0;
	while (y < (vars.map_y))
	{
		x = 0;
		while (x < (vars.map_x))
		{
			printf("map[%d][%d]: %d\n", y, x, vars.map[y][x]);
			x++;
		}
		y++;
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map_x * GRID, vars.map_y * GRID, "Blumenfeld");
	vars.rock = mlx_xpm_file_to_image(vars.mlx, rock_path, &img_width, &img_height);
	vars.exit = mlx_xpm_file_to_image(vars.mlx, exit_path, &img_width, &img_height);
	vars.grass = mlx_xpm_file_to_image(vars.mlx, grass_path, &img_width, &img_height);
	vars.tree = mlx_xpm_file_to_image(vars.mlx, tree_path, &img_width, &img_height);
	vars.tulecie = mlx_xpm_file_to_image(vars.mlx, tulecie_path, &img_width, &img_height);
	vars.rock = mlx_xpm_file_to_image(vars.mlx, rock_path, &img_width, &img_height);
	vars.grass = mlx_xpm_file_to_image(vars.mlx, grass_path, &img_width, &img_height);
	mlx_key_hook(vars.win, key_hook, &vars);
	vars.map = map_refresh();
	j = 0;
	while (j < (vars.map_y))
	{
		i = 0;
		while (i < (vars.map_x))
		{
			if (vars.map[j][i] == '0')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.grass, i * GRID, j * GRID);
			else if (vars.map[j][i] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tree, i * GRID, j * GRID);
			else if (vars.map[j][i] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tulecie, i * GRID, j * GRID);
			else if (vars.map[j][i] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.exit, i * GRID, j * GRID);
			else if (vars.map[j][i] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.rock, i * GRID, j * GRID);
			i++;
		}
		j++;
	}
	liberator(vars.map, vars.map_y);
	mlx_loop(vars.mlx);
}
