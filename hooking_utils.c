/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:49:55 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/11 13:26:07 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	make_image(t_vars *m)
{
	int	x;
	int	y;

	y = 0;
	while (y < (m->map_y))
	{
		x = 0;
		while (x < (m->map_x))
		{
			mlx_put_image_to_window(m->mlx, m->win, m->grass, x * G, y * G);
			if (m->m[y][x] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->tree, x * G, y * G);
			else if (m->m[y][x] == 'C')
				mlx_put_image_to_window(m->mlx, \
				m->win, m->tulecie, x * G, y * G);
			else if (m->m[y][x] == 'E')
				mlx_put_image_to_window(m->mlx, \
				m->win, m->exit, x * G, y * G);
			else if (m->m[y][x] == 'P')
				mlx_put_image_to_window(m->mlx, \
				m->win, m->rock, x * G, y * G);
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
		if (mlx->m[j][i] == 'N' || mlx->m[j][i] == 'O' \
		|| mlx->m[j][i] == 'M' || mlx->m[j][i] == 'U')
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
		if (mlx->m[j][i] == 'N' || mlx->m[j][i] == 'O' \
		|| mlx->m[j][i] == 'M' || mlx->m[j][i] == 'U')
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
		if (mlx->m[j][i] == 'N' || mlx->m[j][i] == 'O' \
		|| mlx->m[j][i] == 'M' || mlx->m[j][i] == 'U')
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
		if (mlx->m[j][i] == 'N' || mlx->m[j][i] == 'O' \
		|| mlx->m[j][i] == 'M' || mlx->m[j][i] == 'U')
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