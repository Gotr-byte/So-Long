/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:34:56 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/04 11:15:07 by pbiederm         ###   ########.fr       */
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
	int			x;
	int			y;
	int			fd_rw;

	mlx->map = map_reader();
	fd_rw = open("rw_file.ber", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (keycode)
	{
		printf ("xp gained: %i\n", ++xp);
	}
	if (keycode == 53)
		destructor(mlx);
	if (keycode == 126)
	{
		printf ("up key pressed\n");
		if(j > 0 && mlx->map[j - 1][i] != '1')
		{
			mlx->map[j][i] = '0';
			j--;
			mlx->map[j][i] = 'C';
		}
		else
			mlx->map[j][i] = 'C';
		y = 0;
		while (y < (mlx->map_y))
		{
			x = 0;
		while (x < (mlx->map_x))
		{
			write(fd_rw, &mlx->map[y][x], 1);
			if(x == (mlx->map_x -1))
				write(fd_rw, "\n", 1);
			printf("map[%d][%d]: %d\n", y, x, mlx->map[y][x]);
			x++;
		}
		y++;
		}
	}
	if (keycode == 125)
	{
		printf ("down key pressed\n");
		if (j < mlx->map_y && mlx->map[j + 1][i] != '1')
		{
			mlx->map[j][i] = '0';
			j++;
			mlx->map[j][i] = 'C';
		}
		else
			mlx->map[j][i] = 'C';
		y = 0;
		while (y < (mlx->map_y))
		{
			x = 0;
		while (x < (mlx->map_x))
		{
			write(fd_rw, &mlx->map[y][x], 1);
			if(x == (mlx->map_x -1))
				write(fd_rw, "\n", 1);
			printf("map[%d][%d]: %d\n", y, x, mlx->map[y][x]);
			x++;
		}
		y++;
		}
	}
	if (keycode == 123)
	{
		printf ("left key pressed\n");
		if (i > 0 && mlx->map[j][i - 1] != '1')
		{
			mlx->map[j][i] = '0';
			i--;
			mlx->map[j][i] = 'C';
		}
		else
			mlx->map[j][i] = 'C';
		y = 0;
		while (y < (mlx->map_y))
		{
			x = 0;
		while (x < (mlx->map_x))
		{
			write(fd_rw, &mlx->map[y][x], 1);
			if(x == (mlx->map_x -1))
				write(fd_rw, "\n", 1);
			printf("map[%d][%d]: %d\n", y, x, mlx->map[y][x]);
			x++;
		}
		y++;
		}
	}
	if (keycode == 124)
	{
		printf ("right key pressed\n");
		if (i < mlx->map_x && mlx->map[j][i + 1] != '1')
		{
			mlx->map[j][i] = '0';
			i++;
			mlx->map[j][i] = 'C';
		}
		else
			mlx->map[j][i] = 'C';
		y = 0;
		while (y < (mlx->map_y))
		{
			x = 0;
		while (x < (mlx->map_x))
		{
			write(fd_rw, &mlx->map[y][x], 1);
			if(x == (mlx->map_x -1))
				write(fd_rw, "\n", 1);
			printf("map[%d][%d]: %d\n", y, x, mlx->map[y][x]);
			x++;
		}
		y++;
		}
	}
	return (0);
}
