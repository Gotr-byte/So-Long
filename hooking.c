/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:34:56 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/06 20:31:28 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	destructor(t_vars *mlx)
{
	liberator(mlx->m, mlx->map_y);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}

//find a diff way to use the file descriptors
// first rewrite from the map to the new map file which is rewritable
int	key_hook(int keycode, t_vars *mlx)
{
	static int	xp;
	static int	i;
	static int	j;
	static int	gate;
	static int	collected;
	int			x;
	int			y;

	if (gate != 1)
	{
		i = character_pos_x();
		j = character_pos_y();
		gate = 1;
		mlx->m = map_reader();
		mlx->num_collectables = num_collectables(*mlx);
	}
	if (keycode)
	{
		printf ("xp gained: %i\n", ++xp);
	}
	if (keycode == 53)
	{
		destructor(mlx);
	}
	if (keycode == 126)
	{
		printf ("up key pressed\n");
		if (j > 0 && mlx->m[j - 1][i] != '1')
		{
			if (mlx->m[j][i] != 'E')
				mlx->m[j][i] = '0';
			j--;
			if (mlx->m[j][i] == 'C')
				collected++;
			printf("collected: %d\n", collected);
			printf("to collect: %d\n", mlx->num_collectables);
			if (mlx->m[j][i] == 'E' && collected == mlx->num_collectables)
				destructor(mlx);
			if (mlx->m[j][i] != 'E')
				mlx->m[j][i] = 'P';
		}
		else
			mlx->m[j][i] = 'P';
	}
	if (keycode == 125)
	{
		printf ("down key pressed\n");
		if (j < mlx->map_y && mlx->m[j + 1][i] != '1')
		{
			if (mlx->m[j][i] != 'E')
				mlx->m[j][i] = '0';
			j++;
			if (mlx->m[j][i] == 'C')
				collected++;
			printf("collected: %d\n", collected);
			printf("to collect: %d\n", mlx->num_collectables);
			if (mlx->m[j][i] == 'E' && collected == mlx->num_collectables)
				destructor(mlx);
			if (mlx->m[j][i] != 'E')
				mlx->m[j][i] = 'P';
		}
		else
			mlx->m[j][i] = 'P';
	}
	if (keycode == 123)
	{
		printf ("left key pressed\n");
		if (i > 0 && mlx->m[j][i - 1] != '1')
		{
			if (mlx->m[j][i] != 'E')
				mlx->m[j][i] = '0';
			i--;
			if (mlx->m[j][i] == 'C')
				collected++;
			printf("collected: %d\n", collected);
			printf("to collect: %d\n", mlx->num_collectables);
			if (mlx->m[j][i] == 'E' && collected == mlx->num_collectables)
				destructor(mlx);
			if (mlx->m[j][i] != 'E')
				mlx->m[j][i] = 'P';
		}
		else
			mlx->m[j][i] = 'P';
	}
	if (keycode == 124)
	{
		printf ("right key pressed\n");
		if (i < mlx->map_x && mlx->m[j][i + 1] != '1')
		{
			if (mlx->m[j][i] != 'E')
				mlx->m[j][i] = '0';
			i++;
			if (mlx->m[j][i] == 'C')
				collected++;
			printf("collected: %d\n", collected);
			printf("to collect: %d\n", mlx->num_collectables);
			if (mlx->m[j][i] == 'E' && collected == mlx->num_collectables)
				destructor(mlx);
			if (mlx->m[j][i] != 'E')
				mlx->m[j][i] = 'P';
		}
		else
			mlx->m[j][i] = 'P';
	}
	y = 0;
	while (y < (mlx->map_y))
	{
		x = 0;
		while (x < (mlx->map_x))
		{
			if (mlx->m[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->grass, x * GRID, y * GRID);
			else if (mlx->m[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tree, x * GRID, y * GRID);
			else if (mlx->m[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->tulecie, x * GRID, y * GRID);
			else if (mlx->m[y][x] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit, x * GRID, y * GRID);
			else if (mlx->m[y][x] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->rock, x * GRID, y * GRID);
			x++;
		}
		y++;
	}
	return (0);
}
