/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:34:56 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/11 15:15:05 by pbiederm         ###   ########.fr       */
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

int	print_num_moves(t_vars	*mlx, int xp)
{
	char	*tmp;

	tmp = ft_itoa(xp + 1);
	ft_printf("made: %d moves\n", xp + 1);
	mlx_put_image_to_window(mlx->mlx, mlx->win, \
	mlx->grass, G * (mlx->map_x + 2), 10);
	mlx_string_put(mlx->mlx, mlx->win, G * \
	(mlx->map_x + 2), 10, 0x00FF0000, tmp);
	free(tmp);
	return (1);
}

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
	}
	if (keycode)
		xp = xp + print_num_moves(mlx, xp);
	if (keycode == 53)
		destructor(mlx);
	if (keycode == 126)
		j = j - move_up(mlx, j, i);
	if (keycode == 125)
		j = j + move_down(mlx, j, i);
	if (keycode == 123)
		i = i - move_left(mlx, j, i);
	if (keycode == 124)
		i = i + move_right(mlx, j, i);
	return (0);
}

void	map_value_rotation(t_vars	*mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < (mlx->map_y))
	{
		x = 0;
		while (x < (mlx->map_x))
		{
			if (mlx->m[y][x] == 'N')
				mlx->m[y][x] = 'O';
			else if (mlx->m[y][x] == 'O')
				mlx->m[y][x] = 'M';
			else if (mlx->m[y][x] == 'M')
				mlx->m[y][x] = 'U';
			else if (mlx->m[y][x] == 'U')
				mlx->m[y][x] = 'N';
			x++;
		}
		y++;
	}
}
