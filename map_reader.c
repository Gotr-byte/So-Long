/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:29:12 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/04 15:28:19 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(void)
{
	int		fd_to_read_height;
	int		ret_height;
	char	*tmp;

	fd_to_read_height = open("map.ber", O_RDONLY);
	ret_height = 0;
	while (TRUE)
	{
		tmp = get_next_line(fd_to_read_height);
		if (tmp == NULL)
		{
			free(tmp);
			break ;
		}
		free(tmp);
		ret_height++;
	}
	close(fd_to_read_height);
	return (ret_height);
}

int	map_width(void)
{
	int		fd_to_read_width;
	char	*tmp;
	int		ret_width;

	fd_to_read_width = open("map.ber", O_RDONLY);
	tmp = get_next_line(fd_to_read_width);
	ret_width = ft_strlen(tmp);
	free(tmp);
	close(fd_to_read_width);
	return (ret_width - NULL_VAL);
}

char	**map_reader(void)
{
	char		**map;
	int		map_y;
	int		map_x;
	int		fd_to_read;
	char	*map_data;
	int 	i;
	int 	j;

	map_x = map_width();
	map_y = map_height();
	fd_to_read = open("map.ber", O_RDONLY);
	map = (char **)ft_calloc(map_y, sizeof(char *));
	j = 0;
	while (j < (map_y))
	{
		i = 0;
		map_data = get_next_line(fd_to_read);
		map[j] = (char *)ft_calloc(map_x, sizeof(char));
		while (i < (map_x))
		{	
			map[j][i] = map_data[i];
			i++;
		}
		free(map_data);
		j++;
	}
	close(fd_to_read);
	return (map);
}

void	**map_refresh(t_vars mlx)
{
	char		**map_tmp;
	int			x;
	int			y;

	map_tmp = **map_reader();
	y = 0;
	while (y < mlx.map_y)
	{
		x = 0;
		while (x < (mlx.map_x))
		{
			write(fd_rw, &mlx.map[y][x], 1);
			if (x == (mlx.map_x -1))
				write(fd_rw, "\n", 1);
			printf("map[%d][%d]: %d\n", y, x, mlx.map[y][x]);
			x++;
		}
		y++;
	}
	liberator(map_tmp, mlx->map_y);
}
