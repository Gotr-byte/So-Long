/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_ii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:23:52 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/07 17:36:39 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strlen_int(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	check_rect(t_vars *vars)
{
	int		y;
	int		fd_check;
	char	*tmp;
	int		check_val;

	fd_check = open("map.ber", O_RDONLY);
	y = 0;
	while (y < vars->map_y)
	{
		tmp = get_next_line(fd_check);
		if (y == vars->map_y - 1)
			check_val = ft_strlen_int(tmp);
		else
			check_val = ft_strlen_int(tmp) - NULL_VAL;
		if (vars->map_x != check_val)
		{
			free(tmp);
			close(fd_check);
			write(2, "Error: invalid map shape\n", 26);
			exit (2);
		}
		y++;
		free(tmp);
	}
	close(fd_check);
}

int	num_collectables(t_vars *vars)
{
	int		x;
	int		y;
	int		count;

	x = 0;
	y = 0;
	count = 0;
	while (y < vars->map_y)
	{
		x = 0;
		while (x < vars->map_x)
		{
			if (vars->m[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	if (count < 1)
	{
		write (2, "Map error: to few collectables\n", 32);
		exit (2);
	}
	return (count);
}

void	invalid_values(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < vars->map_y)
	{
		x = 0;
		while (x < vars->map_x)
		{
			if (vars->m[y][x] != 'C' && vars->m[y][x] != 'E' && \
			vars->m[y][x] != 'P' && vars->m[y][x] != '0' && vars->m[y][x] != '1')
			{
				write(2, "Map error: invalid values\n", 27);
				exit(2);
			}
			else
				x++;
		}
		y++;
	}
	return ;
}
