/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_ii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:23:52 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/06 13:32:35 by pbiederm         ###   ########.fr       */
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

void	check_rect(t_vars vars)
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
		if (y == vars.map_y - 1)
			check_val = ft_strlen_int(tmp);
		else
			check_val = ft_strlen_int(tmp) - NULL_VAL;
		if (vars.map_x != check_val)
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

static void err_msg_many(void)
{
	write (2, "Map error: to many characters\n", 30);
	exit (2);
}

static void err_msg_exits(void)
{
	write (2, "Map error: to many exits\n", 26);
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

int	num_collectables(t_vars vars)
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
			if (vars.m[y][x] == 'C')
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

// void	invalid_values(t_vars vars)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (y < vars.map_y)
// 	{
// 		x = 0;
// 		while (x < vars.map_x)
// 		{
// 			if (vars.m[y][x] == 'C')
// 				x++;
// 			if (vars.m[y][x] == 'E')
// 				x++;
// 			if (vars.m[y][x] == '1')
// 				x++;
// 			if (vars.m[y][x] == '0')
// 				x++;
// 			if (vars.m[y][x] == 'C' && vars.m[y][x] == 'C' && vars.m[y][x] == 'C' && vars.m[y][x] == 'C')
// 			write(2, "Map error: invalid values\n", 27);
// 			exit(2);
// 		}
// 		y++;
// 	}
// 	return ;
// }
