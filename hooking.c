/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:34:56 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/30 11:42:09 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"
#include "stdio.h"
// # include "./mlx/mlx.h"
// #include "unistd.h"
#define grid 48


typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*rock;
}t_vars;

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

	// printf("Hello from the key_hook %i\n", keycode);
	if (keycode)
		printf ("xp gained: %i\n", ++xp);
	if (keycode == 53)
		destructor(mlx);
	if (keycode == 126)
		{
			printf ("up key pressed\n");
			if(i == 0)
				i = 1;
			if(j < 10)
				j++;
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->rock, i * grid, j * grid);
		}
	if (keycode == 125)
	{
		printf ("down key pressed\n");
		if(i < 1)
			i = 1;
		if (j > 0)
			j--;
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->rock, i * grid, j * grid);
	}
	if (keycode == 123)
	{
		printf ("left key pressed\n");
		if (i > 0)
			i--;
		if (j < 1)
			j = 1;
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->rock, i * grid, j * grid);

	}
	if (keycode == 124)
	{
		printf ("right key pressed\n");
		i++;
		if (j < 1)
			j = 1;
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->rock, i * grid, j * grid);
	}

	return (0);
}

int	main(void)
{
	t_vars	vars;
	char	*rock_path = "./xpm/grass.xpm";
	int		img_width;
	int		img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!\n");
	vars.rock = mlx_xpm_file_to_image(vars.mlx, rock_path, &img_width, &img_height);
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); 
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
