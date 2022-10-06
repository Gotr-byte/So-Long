/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_iii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:40:50 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/06 19:42:48 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	err_msg_exits(void)
{
	write (2, "Map error: to many exits\n", 26);
	exit (2);
}

void	num_exits(t_vars vars)
{
	int		x;
	int		y;
	int		count;

	x = 0;
	y = 0;
	count = 0;
	while (y < vars.map_y)
	{
		x = 0;
		while (x < vars.map_x)
		{
			if (vars.m[y][x] == 'E')
				count++;
			if (count > 1)
				err_msg_exits();
			x++;
		}
		y++;
	}
	if (count < 1)
	{
		write (2, "Map error: to few exits\n", 25);
		exit (2);
	}
}

static void	err_msg_many(void)
{
	write (2, "Map error: to many characters\n", 30);
	exit (2);
}

//checks if there is one character value in the map
void	num_characters(t_vars vars)
{
	int		x;
	int		y;
	int		count;

	x = 0;
	y = 0;
	count = 0;
	while (y < vars.map_y)
	{
		x = 0;
		while (x < vars.map_x)
		{
			if (vars.m[y][x] == 'P')
				count++;
			if (count > 1)
				err_msg_many();
			x++;
		}
		y++;
	}
	if (count < 1)
	{
		write (2, "Map error: to few characters\n", 30);
		exit (2);
	}
}
