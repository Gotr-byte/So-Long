/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:34:56 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/28 21:38:02 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./so_long.h"
// #include "stdio.h"
// # include "./mlx/mlx.h"
// #include "unistd.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}t_vars;

void	destructor(t_vars *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}

int	key_hook(int keycode, t_vars *mlx)
{
	static int	xp;

	// printf("Hello from the key_hook %i\n", keycode);
	if (keycode)
		printf ("xp gained: %i\n", ++xp);
	if (keycode == 53)
		destructor(mlx);
	if (keycode == 126)
		printf ("up key pressed\n");
	if (keycode == 125)
		printf ("down key pressed\n");
	if (keycode == 123)
		printf ("left key pressed\n");
	if (keycode == 124)
		printf ("right key pressed\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!\n");
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!"); 
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
