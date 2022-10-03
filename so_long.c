/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:47:04 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/03 12:23:00 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

//need a function that counts the number of lines in the file
//need a map checker
//need movement hookers

void	liberator(int	**map, int map_height)
{
	int	j;

	j = 0;
	while(j < map_height)
	{
		free(map[j]);
		j++;
	}
}

int	map_height(void)
{
	int		fd_to_read_height;
	int		ret_height;
	char	*tmp;

	fd_to_read_height = open("map.ber", O_RDONLY);
	ret_height = 0;
	while (1)
		{
			tmp = get_next_line(fd_to_read_height);
			if (tmp == NULL)
			{
				free(tmp);
				break ;
			}
			free(tmp);
			ret_height++;
		}
	close(fd_to_read_height);
	return (ret_height);
}

int	map_width(void)
{
	int		fd_to_read_width;
	char	*tmp;
	int		ret_width;
	
	fd_to_read_width = open("map.ber", O_RDONLY);
	tmp = get_next_line(fd_to_read_width);
	ret_width = ft_strlen(tmp);
	free(tmp);
	close(fd_to_read_width);
	return (ret_width - NULL_VAL);
}
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
	int		**map;
	char	*map_data;
	int		i;
	int		j;
	int		fd_to_read;
	int		map_y;
	int		map_x;

	fd_to_read = open("map.ber", O_RDONLY);
	map = (int **)malloc(5 * sizeof(int *));
	j = 0;
	map_y = map_height();
	map_x = map_width();
	while (j < (map_y))
	{
		i = 0;
		map_data = get_next_line(fd_to_read);
		map[j] = (int *)ft_calloc((map_x), sizeof(int));
		while (i < (map_x))
		{	
			map[j][i] = map_data[i];
			i++;
		}
		free(map_data);
		j++;
	}
	j = 0;
	while (j < (map_y))
	{
		i = 0;
		while (i < (map_x))
		{
			printf("value in map[%d][%i], is equal: %d\n", j, i, map[j][i]);
			i++;
		}
		j++;
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, map_x * GRID, map_y * GRID, "Blumenfeld");
	vars.rock = mlx_xpm_file_to_image(vars.mlx, rock_path, &img_width, &img_height);
	vars.exit = mlx_xpm_file_to_image(vars.mlx, exit_path, &img_width, &img_height);
	vars.grass = mlx_xpm_file_to_image(vars.mlx, grass_path, &img_width, &img_height);
	vars.tree = mlx_xpm_file_to_image(vars.mlx, tree_path, &img_width, &img_height);
	vars.tulecie = mlx_xpm_file_to_image(vars.mlx, tulecie_path, &img_width, &img_height);
	// img_putter(vars, map, map_x, map_y);
	j = 0;
	while (j < (map_y))
	{
		i = 0;
		while (i < (map_x))
		{
			if (map[j][i] == '0')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.grass, i * GRID, j * GRID);
			else if (map[j][i] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tree, i * GRID, j * GRID);
			else if (map[j][i] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tulecie, i * GRID, j * GRID);
			else if (map[j][i] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.exit, i * GRID, j * GRID);
			else if (map[j][i] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.rock, i * GRID, j * GRID);
			i++;
		}
		j++;
	}
	vars.rock = mlx_xpm_file_to_image(vars.mlx, rock_path, &img_width, &img_height);
	vars.grass = mlx_xpm_file_to_image(vars.mlx, grass_path, &img_width, &img_height);
	mlx_key_hook(vars.win, key_hook, &vars);
	liberator(map, map_y);
	close(fd_to_read);
	mlx_loop(vars.mlx);
}
