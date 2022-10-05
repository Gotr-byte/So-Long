/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_mask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:15:28 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/05 12:35:27 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	destructor(t_vars *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}

void cross_mask (t_vars *mlx, int j, int i)
{
	if (mlx->map[j - 1][i] != '1')
		mlx->map[j - 1][i] = 'M';
	if (mlx->map[j][i - 1] != '1')
		mlx->map[j][i - 1] = 'M';
	mlx->map[j][i] = 'M';
	if (mlx->map[j][i + 1] != '1')
		mlx->map[j][i + 1] = 'M';
	if (mlx->map [j + 1][i] != '1')
	mlx->map[j + 1][i] = 'M';
}

int	key_hook_mask(int keycode, t_vars *mlx)
{
	static int		xp;
	static int		i;
	static int		j;
	int				fd_rw;
	static	int		gate;
	static int		light;
	int				x;
	int				y;

	if (gate != 1)
	{
		i = 5;
		j = 5;
		gate = 1;
	}

	// map_refresh(*mlx);
	mlx->map = map_reader();
	fd_rw = open("rw_file.ber", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (keycode)
	{
		printf ("xp gained: %i\n", ++xp);
	
	}
	if (keycode == 53)
	{
		if(mlx->map[j - light][i] != '1' || mlx->map[j + light][i] != '1' || mlx->map[j][i - light] != '1' || mlx->map[j][i + light] != '1')
		{

			mlx->map[j - light][i] = 'M';
			mlx->map[j][i - light] = 'M';
			mlx->map[j][i] = 'M';
			mlx->map[j][i + light] = 'M';
			mlx->map[j + light][i] = 'M';
			j++;
			mlx->map[j - light][i] = 'M';
			mlx->map[j][i - light] = 'M';
			mlx->map[j][i] = 'M';
			mlx->map[j][i + light] = 'M';
			mlx->map[j + light][i] = 'M';
			j--;
			j--;
			mlx->map[j - light][i] = 'M';
			mlx->map[j][i - light] = 'M';
			mlx->map[j][i] = 'M';
			mlx->map[j][i + light] = 'M';
			mlx->map[j + light][i] = 'M';
			j++;
			i--;
			mlx->map[j - light][i] = 'M';
			mlx->map[j][i - light] = 'M';
			mlx->map[j][i] = 'M';
			mlx->map[j][i + light] = 'M';
			mlx->map[j + light][i] = 'M';
			i++;
			i++;
			mlx->map[j - light][i] = 'M';
			mlx->map[j][i - light] = 'M';
			mlx->map[j][i] = 'M';
			mlx->map[j][i + light] = 'M';
			mlx->map[j + light][i] = 'M';
			i--;
			light++;
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
	}
	if (keycode == 126)
	{
		printf ("up key pressed\n");
		if(j > 0 && mlx->map[j - 1][i] != '1')
		{
			mlx->map[j][i] = 'o';
			j--;
			mlx->map[j - 1][i] = 'M';
			mlx->map[j][i - 1] = 'M';
			mlx->map[j][i] = 'M';
			mlx->map[j][i + 1] = 'M';
			mlx->map[j + 1][i] = 'M';
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
		else
			mlx->map[j][i] = 'M';
	}
	if (keycode == 125)
	{
		printf ("down key pressed\n");
		if (j < mlx->map_y && mlx->map[j + 1][i] != '1')
		{
			mlx->map[j][i] = 'o';
			j++;
			mlx->map[j - 1][i] = 'M';
			mlx->map[j][i - 1] = 'M';
			mlx->map[j][i] = 'M';
			mlx->map[j][i + 1] = 'M';
			mlx->map[j + 1][i] = 'M';
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
		else
			mlx->map[j][i] = 'M';
	}
	if (keycode == 123)
	{
		printf ("left key pressed\n");
		if (i > 0 && mlx->map[j][i - 1] != '1')
		{
			mlx->map[j][i] = 'o';
			i--;
			mlx->map[j - 1][i] = 'M';
			mlx->map[j][i - 1] = 'M';
			mlx->map[j][i] = 'M';
			mlx->map[j][i + 1] = 'M';
			mlx->map[j + 1][i] = 'M';
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
		else
			mlx->map[j][i] = 'M';
	}
	if (keycode == 124)
	{
		printf ("right key pressed\n");
		if (i < mlx->map_x && mlx->map[j][i + 1] != '1')
		{
			mlx->map[j][i] = 'o';
			i++;
			// mlx->map[j - 1][i] = 'M';
			mlx->map[j][i - 1] = 'M';
			mlx->map[j][i] = 'M';
			mlx->map[j][i + 1] = 'M';
			mlx->map[j + 1][i] = 'M';
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
		else
			mlx->map[j][i] = 'M';
	}
	return (0);
}
