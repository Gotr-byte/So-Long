/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intravid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:19:49 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/27 17:31:53 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mlx.h"

int deal_key()
{
	
}

int main ()
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(mlx_ptr, deal_key, void0)
	mlx_loop(mlx_ptr);
}
