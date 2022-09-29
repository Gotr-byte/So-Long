/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:47:04 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/29 14:23:41 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"
#include <stdio.h>

#define grid 48

t_grid	*ft_gridnew(int data, int pos_x, int pos_y)
{
	t_grid	*tmp;

	tmp = (t_grid *)malloc(sizeof(t_grid));
	if (!tmp)
		return (NULL);
	if (tmp)
	{
		tmp->data = data;
		tmp->pos_x = pos_x;
		tmp->pos_y = pos_y;
		tmp->up = NULL;
		tmp->right = NULL;
		tmp->down = NULL;
		tmp->left = NULL;
	}
	return (tmp);
}

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



int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	char	*grass_path = "./xpm/grass.xpm";
	char	*tree_path = "./xpm/tree.xpm";
	int		img_width;
	int		img_height;
	void	*grass;
	void	*tree;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	grass = mlx_xpm_file_to_image(mlx, grass_path, &img_width, &img_height);
	tree = mlx_xpm_file_to_image(mlx, tree_path, &img_width, &img_height);
	while (i < 10)
	{
		mlx_put_image_to_window(mlx, mlx_win, grass, i * grid, j * grid);
		i++;
	}
	i = 0;
	j = 1;
	while (i < 10)
	{
		mlx_put_image_to_window(mlx, mlx_win, tree, i * grid, j * grid);
		i++;
		j++;
	}
	mlx_loop(mlx);
}
