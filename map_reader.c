/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:29:12 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/04 12:44:22 by pbiederm         ###   ########.fr       */
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

char	**map_refresh(void)
{
	char		**map;
	int		map_y;
	int		map_x;
	int		fd_to_read;
	char	*map_data;
	int 	i;
	int 	j;

	map_y = map_height();
	map_x = map_width();
	fd_to_read = open("rw_file.ber", O_RDONLY);
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
	j = 0;
	close(fd_to_read);
	return (map);
}

