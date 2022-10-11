/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:50:54 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/11 14:58:38 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	image_put(t_vars	*mlx)
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
				mlx_put_image_to_window(mlx->mlx, mlx->win, \
				mlx->warlock[0], x * G, y * G);
			if (mlx->m[y][x] == 'O')
				mlx_put_image_to_window(mlx->mlx, mlx->win, \
				mlx->grass, x * G, y * G);
			if (mlx->m[y][x] == 'M')
				mlx_put_image_to_window(mlx->mlx, mlx->win, \
				mlx->warlock[1], x * G, y * G);
			if (mlx->m[y][x] == 'U')
				mlx_put_image_to_window(mlx->mlx, mlx->win, \
				mlx->grass, x * G, y * G);
			x++;
		}
		y++;
	}
}

int	loop_hook(t_vars *mlx)
{
	make_image(mlx);
	usleep(65800);
	map_value_rotation(mlx);
	image_put(mlx);
	return (0);
}
