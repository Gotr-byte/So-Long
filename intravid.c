/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intravid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:19:49 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/28 14:22:03 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

void ft_putchar (char c)
{
	write (1, &c, 1);
}

int deal_key(int key)
{
	ft_putchar('X');
	ft_putchar('\n');
	printf("Congratulations you hit the key: %i\n", key);
	return (0);
}

int main ()
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(mlx_ptr, deal_key, 0);
	mlx_loop(mlx_ptr);
}
