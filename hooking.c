/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:34:56 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/07 20:01:08 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	num_collect_hook(t_vars *vars)
{
	int		x;
	int		y;
	int		count;

	x = 0;
	y = 0;
	count = 0;
	while (y < vars->map_y)
	{
		x = 0;
		while (x < vars->map_x)
		{
			if (vars->m[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

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

	if (gate != 1)
	{
		i = character_pos_x();
		j = character_pos_y();
		gate = 1;
		// mlx->m = map_reader();
		// mlx->map_x = map_width();
		// mlx->map_y = map_height();
		// mlx->num_collectables = num_collect_hook(mlx);
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
		j = j - move_up(mlx, j, i);
	if (keycode == 125)
		j = j + move_down(mlx, j, i);
	if (keycode == 123)
		i = i - move_left(mlx, j, i);
	if (keycode == 124)
		i = i + move_right(mlx, j, i);
	make_image(mlx);
	return (0);
}

int	loop_hook(t_vars *mlx)
{
	int x;
	int y;
	static int i;

	usleep(65800);

	// mlx->m = map_reader();
	y = 0;
	while (y < (mlx->map_y))
	{
		x = 0;
		while (x < (mlx->map_x))
		{
			if (mlx->m[y][x] == 'N')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->warlock[i], x * GRID, y * GRID);
			x++;
		}
		y++;
	}
	i++;
	if (i == 2)
		i = 0;
	return (0);
}
