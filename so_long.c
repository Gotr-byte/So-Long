/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:47:04 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/27 19:21:48 by pbiederm         ###   ########.fr       */
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

// void	rectangle(int x_tmp, int y, int size, t_data* img)
// {
// 	int	x;

// 	x = x_tmp;
// 	while (y < y + size)
// 	{
// 		x = x_tmp;
// 		while (x < x + size)
// 		{
// 			my_mlx_pixel_put(img, x, y, 0x0000CC00);
// 			x++;
// 		}
// 		my_mlx_pixel_put(img, x, y, 0x0000CC00);
// 		y++;
// 	}
// }

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	// int 	x1;
	// int 	y1;
	// int		i;
	void	*img_upload;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img_upload = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	// rectangle
	// rectangle(150, 150,  100, &img);
	y = 5;
	while (y < 100)
	{
		x = 5;
		while (x < 100)
		{
			my_mlx_pixel_put(&img, x, y, 0x0000CC00);
			x++;
		}
		my_mlx_pixel_put(&img, x, y, 0x0000CC00);
		y++;
	}
	y = 45;
	while (y < 100)
	{
		x = 45;
		while (x < 500)
		{
			my_mlx_pixel_put(&img, x, y, 0xAAFFFF00);
			x++;
		}
		my_mlx_pixel_put(&img, x, y, 0x08FFFF00);
		y++;
	}
	x = 605;
	y = 5;
	while (y < 100)
	{
		x = 605;
		while (x < 700)
		{
			my_mlx_pixel_put(&img, x, y, 0x000000CC);
			x++;
		}
		my_mlx_pixel_put(&img, x, y, 0x000000CC);
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img_upload, 0, 0);
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
