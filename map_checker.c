/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:11:15 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/04 13:15:33 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_nort_wall(t_vars vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < vars.map_x)
	{
		if (vars.map[y][x] != '1')
		{
			write(2, "Error: invalid map\n", 20);
			exit (2);
		}
		x++;
	}
}

void	check_west_wall(t_vars vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < vars.map_y)
	{
		if (vars.map[y][x] != '1')
		{
			write(2, "Error: invalid map\n", 20);
			exit (2);
		}
		y++;
	}
}

void	check_east_wall(t_vars vars)
{
	int	x;
	int	y;

	x = vars.map_x - NULL_VAL;
	y = 0;
	while (y < vars.map_y)
	{
		if (vars.map[y][x] != '1')
		{
			write(2, "Error: invalid map\n", 20);
			exit (2);
		}
		y++;
	}
}

void	check_south_wall(t_vars vars)
{
	int	x;
	int	y;

	x = 0;
	y = vars.map_y - NULL_VAL;
	while (x < vars.map_x)
	{
		if (vars.map[y][x] != '1')
		{
			write(2, "Error: invalid map\n", 20);
			exit (2);
		}
		x++;
	}
}

int	ft_strlen_int(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


void check_rect(t_vars vars)
{
	int		y;
	int		fd_check;
	char	*tmp;
	int		check_val;

	fd_check = open("map.ber", O_RDONLY);
	y = 0;
	while (y < vars.map_y)
	{
		tmp = get_next_line(fd_check);
		if(y == vars.map_y - 1)
			check_val = ft_strlen_int(tmp);
		else
			check_val = ft_strlen_int(tmp) - NULL_VAL;
		if(vars.map_x != check_val)
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