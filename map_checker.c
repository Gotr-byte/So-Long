/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:11:15 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/07 17:35:15 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_nort_wall(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < vars->map_x)
	{
		if (vars->m[y][x] != '1')
		{
			write(2, "Error: invalid map\n", 20);
			exit (2);
		}
		x++;
	}
}

void	check_west_wall(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < vars->map_y)
	{
		if (vars->m[y][x] != '1')
		{
			write(2, "Error: invalid map\n", 20);
			exit (2);
		}
		y++;
	}
}

void	check_east_wall(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->map_x - NULL_VAL;
	y = 0;
	while (y < vars->map_y)
	{
		if (vars->m[y][x] != '1')
		{
			write(2, "Error: invalid map\n", 20);
			exit (2);
		}
		y++;
	}
}

void	check_south_wall(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = vars->map_y - NULL_VAL;
	while (x < vars->map_x)
	{
		if (vars->m[y][x] != '1')
		{
			write(2, "Error: invalid map\n", 20);
			exit (2);
		}
		x++;
	}
}
