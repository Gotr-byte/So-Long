/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:47:04 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/27 12:34:33 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

#include <mlx.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	// int 	x1;
	// int 	y1;
	int		i;

	y = 5;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	
	// rectangle
	while (y < 100)
	{
		x = 5;
		while (x < 100)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		y++;
	}

	//triangle
	x = 205;
	y = 205;
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(&img, x + i, y, 0x00FF0000);
		my_mlx_pixel_put(&img, x + i, y + i, 0x00FF0000);
		my_mlx_pixel_put(&img, x + 100, y + i, 0x00FF0000);
		i++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
