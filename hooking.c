/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:34:56 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/03 17:49:52 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	destructor(t_vars *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}

int	key_hook(int keycode, t_vars *mlx)
{
	static int	xp;
	static int	i;
	static int	j;
	int			rw_fd;
	int			x;
	int			y;

	mlx->map = map_reader();
	if (keycode)
	{
		y = 0;
		while (y < (mlx->map_y))
		{
			x = 0;
			while (x < (mlx->map_x))
			{
				printf("map[%d][%d]: %d\n", y, x, mlx->map[y][x]);
				x++;
			}
			y++;
		}
		printf ("xp gained: %i\n", ++xp);
	}
	if (keycode == 53)
		destructor(mlx);
	if (keycode == 126)
		{
			printf ("up key pressed\n");
			if(j > 0)
			{
				mlx->map[j][i] = '0';
				j--;
				mlx->map[j][i] = 'C';
			}
		}
	if (keycode == 125)
	{
		printf ("down key pressed\n");
		if (j < mlx->map_y)
		{
			mlx->map[j][i] = '0';
			j++;
			mlx->map[j][i] = 'C';
		}
	}
	if (keycode == 123)
	{
		printf ("left key pressed\n");
		if (i > 0)
		{
			mlx->map[j][i] = '0';
			i--;
			mlx->map[j][i] = 'C';
		}
	}
	if (keycode == 124)
	{
		printf ("right key pressed\n");
		if (i < mlx->map_x)
		{
			mlx->map[j][i] = '0';
			i++;
			mlx->map[j][i] = 'C';
		}
	}
	return (0);
}
