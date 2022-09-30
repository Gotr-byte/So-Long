/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:47:04 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/30 12:40:53 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"
#include "./get_next_line.h"
#include <stdio.h>

#define grid 48

// t_grid	*ft_gridnew(int data, int pos_x, int pos_y)
// {
// 	t_grid	*tmp;

// 	tmp = (t_grid *)malloc(sizeof(t_grid));
// 	if (!tmp)
// 		return (NULL);
// 	if (tmp)
// 	{
// 		tmp->data = data;
// 		tmp->pos_x = pos_x;
// 		tmp->pos_y = pos_y;
// 		tmp->up = NULL;
// 		tmp->right = NULL;
// 		tmp->down = NULL;
// 		tmp->left = NULL;
// 	}
// 	return (tmp);
// }

// int	main(void)
// {
// 	t_grid	*grid_head;
// 	t_grid	*traverse;
// 	t_grid	*grid00;
// 	t_grid	*grid10;
// 	t_grid	*grid01;

// 	traverse = NULL;
// 	grid00 = ft_gridnew(11, 0, 0);
// 	grid_head = grid00;
// 	grid10 = ft_gridnew(10, 1, 0);
// 	grid00->right = grid10;
// 	grid10->left = grid00;
// 	grid01 = ft_gridnew(01, 0, 1);
// 	grid00->down = grid01;
// 	grid01->up = grid00;
// 	printf("%d\n", grid_head->data);
// 	traverse = grid_head;
// 	traverse = traverse->down;
// 	printf("%d\n", traverse->data);
// 	traverse = traverse->up;
// 	printf("%d\n", traverse->data);

// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	char	*grass_path = "./xpm/grass.xpm";
// 	char	*tree_path = "./xpm/tree.xpm";
// 	int		img_width;
// 	int		img_height;
// 	void	*grass;
// 	void	*tree;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
// 	grass = mlx_xpm_file_to_image(mlx, grass_path, &img_width, &img_height);
// 	tree = mlx_xpm_file_to_image(mlx, tree_path, &img_width, &img_height);
// 	while (i < 10)
// 	{
// 		mlx_put_image_to_window(mlx, mlx_win, grass, i * grid, j * grid);
// 		i++;
// 	}
// 	i = 0;
// 	j = 1;
// 	while (i < 10)
// 	{
// 		mlx_put_image_to_window(mlx, mlx_win, tree, i * grid, j * grid);
// 		i++;
// 		j++;
// 	}
// 	mlx_loop(mlx);
// }

//need a function that counts the number of lines in the file
//need a map checker
//need movement hookers

#define null_pointer 1
int	main(void)
{
	t_vars	vars;
	// void	*mlx;
	// void	*mlx_win;
	char	*grass_path = "./xpm/grass.xpm";
	char	*tree_path = "./xpm/tree.xpm";
	char	*tulecie_path = "./xpm/tulecie.xpm";
	char	*exit_path = "./xpm/exit.xpm";
	char	*rock_path = "./xpm/rock.xpm";
	int		img_width;
	int		img_height;
	// void	*grass;
	// void	*tree;
	// void	*tulecie;
	// void	*exit;
	// void	*rock;
	int		**map;
	char	*map_data;
	int	i;
	int		j;
	int		fd_to_read;
	
	fd_to_read = open("map.ber", O_RDONLY);
	map = (int **)malloc(5 * sizeof(int *));
	j = 1;
	while (j < 6)
	{
		i = 0;
		map_data = get_next_line(fd_to_read);
		map[j-1] = (int *)malloc(13 * sizeof(int));
		while (i < 13)
		{	
			map[j - 1][i] = map_data[i];
			i++;
		}
		free(map_data);
		j++;
	}
	j = 1;
	while (j < 6)
	{
		i = 0;
		while (i < 13)
		{
			printf("value in map[%d][%i], is equal: %d\n", j, i, map[j - 1][i]);
			i++;
		}
		j++;
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 500, "Blumenfeld");
	vars.rock = mlx_xpm_file_to_image(vars.mlx, rock_path, &img_width, &img_height);
	vars.exit = mlx_xpm_file_to_image(vars.mlx, exit_path, &img_width, &img_height);
	vars.grass = mlx_xpm_file_to_image(vars.mlx, grass_path, &img_width, &img_height);
	vars.tree = mlx_xpm_file_to_image(vars.mlx, tree_path, &img_width, &img_height);
	vars.tulecie = mlx_xpm_file_to_image(vars.mlx, tulecie_path, &img_width, &img_height);
	j = 1;
	while (j < 6)
	{
		i = 0;
		while (i < 13)
		{
			if (map[j - 1][i] == '0')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.grass, i * grid, j * grid);
			else if (map[j - 1][i] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tree, i * grid, j * grid);
			else if (map[j - 1][i] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tulecie, i * grid, j * grid);
			else if (map[j - 1][i] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.exit, i * grid, j * grid);
			else if (map[j - 1][i] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, vars.rock, i * grid, j * grid);
			i++;
		}
		j++;
	}
	vars.rock = mlx_xpm_file_to_image(vars.mlx, rock_path, &img_width, &img_height);
	vars.grass = mlx_xpm_file_to_image(vars.mlx, grass_path, &img_width, &img_height);
	mlx_key_hook(vars.win, key_hook, &vars);

	free(*map);
	free(map);
	close(fd_to_read);
	mlx_loop(vars.mlx);
}

// int main(void)
// {
// 	int		fd_to_read;
	
// 	fd_to_read = open("map.ber", O_RDONLY);
// 	while(get_next_line(fd_to_read))
// 		printf("%d\n", fd_to_read);
// 	close(fd_to_read);
// 	fd_to_read = open("map.ber", O_RDONLY);
// 	while(1)
// 	{
// 		if(get_next_line(fd_to_read)==NULL)
// 			{
			// 	break;
			// 	i++;
			// }
// 		else	
// 			printf("read\n");
// 	}
// }
