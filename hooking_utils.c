/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:49:55 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/11 12:23:31 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	make_image(t_vars *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < (mlx->map_y))
	{
		x = 0;
		while (x < (mlx->map_x))
		{
			// if (mlx->m[y][x] == '0')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->grass, x * GRID, y * GRID);
			// else if (mlx->m[y][x] == 'N')
				// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->warlock, x * GRID, y * GRID);
			if (mlx->m[y][x] == '1')
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
}

int	move_right(t_vars *mlx, int j, int i)
{
	printf ("right key pressed\n");
	if (i < mlx->map_x && mlx->m[j][i + 1] != '1')
	{
		if (mlx->m[j][i] != 'E')
			mlx->m[j][i] = '0';
		i++;
		if (mlx->m[j][i] == 'C')
			mlx->num_collectables--;
		printf("to collect: %d\n", mlx->num_collectables);
		if (mlx->m[j][i] == 'E' && mlx->num_collectables == 0)
			destructor(mlx);
		if (mlx->m[j][i] == 'N' || mlx->m[j][i] == 'O' || mlx->m[j][i] == 'M' || mlx->m[j][i] == 'U')
			destructor(mlx);
		if (mlx->m[j][i] != 'E')
			mlx->m[j][i] = 'P';
		return (1);
	}
	else
	{
		mlx->m[j][i] = 'P';
		return (0);
	}
}

int	move_left(t_vars *mlx, int j, int i)
{
	printf ("left key pressed\n");
	if (i < mlx->map_x && mlx->m[j][i - 1] != '1')
	{
		if (mlx->m[j][i] != 'E')
			mlx->m[j][i] = '0';
		i--;
		if (mlx->m[j][i] == 'C')
			mlx->num_collectables--;
		printf("to collect: %d\n", mlx->num_collectables);
		if (mlx->m[j][i] == 'E' && mlx->num_collectables == 0)
			destructor(mlx);
		if (mlx->m[j][i] == 'N')
			destructor(mlx);
		if (mlx->m[j][i] != 'E')
			mlx->m[j][i] = 'P';
		return (1);
	}
	else
	{
		mlx->m[j][i] = 'P';
		return (0);
	}
}

int	move_up(t_vars *mlx, int j, int i)
{
	printf ("up key pressed\n");
	if (j > 0 && mlx->m[j - 1][i] != '1')
	{
		if (mlx->m[j][i] != 'E')
			mlx->m[j][i] = '0';
		j--;
		if (mlx->m[j][i] == 'C')
			mlx->num_collectables--;
		printf("to collect: %d\n", mlx->num_collectables);
		if (mlx->m[j][i] == 'E' && mlx->num_collectables == 0)
			destructor(mlx);
		if (mlx->m[j][i] == 'N')
			destructor(mlx);
		if (mlx->m[j][i] != 'E')
			mlx->m[j][i] = 'P';
		return (1);
	}
	else
	{
		mlx->m[j][i] = 'P';
		return (0);
	}
}

int	move_down(t_vars *mlx, int j, int i)
{
	printf ("down key pressed\n");
	if (j > 0 && mlx->m[j + 1][i] != '1')
	{
		if (mlx->m[j][i] != 'E')
			mlx->m[j][i] = '0';
		j++;
		if (mlx->m[j][i] == 'C')
			mlx->num_collectables--;
		printf("to collect: %d\n", mlx->num_collectables);
		if (mlx->m[j][i] == 'E' && mlx->num_collectables == 0)
			destructor(mlx);
		if (mlx->m[j][i] == 'N')
			destructor(mlx);
		if (mlx->m[j][i] != 'E')
			mlx->m[j][i] = 'P';
		return (1);
	}
	else
	{
		mlx->m[j][i] = 'P';
		return (0);
	}
}