/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_ii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:23:52 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/04 13:25:03 by pbiederm         ###   ########.fr       */
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
