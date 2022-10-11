/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:29:12 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/11 14:48:56 by pbiederm         ###   ########.fr       */
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
	t_map	r;

	r.map_x = map_width();
	r.map_y = map_height();
	r.fd_to_read = open("map.ber", O_RDONLY);
	r.map = (char **)ft_calloc(r.map_y, sizeof(char *));
	r.j = 0;
	while (r.j < (r.map_y))
	{
		r.i = 0;
		r.map_data = get_next_line(r.fd_to_read);
		r.map[r.j] = (char *)ft_calloc(r.map_x, sizeof(char));
		while (r.i < (r.map_x))
		{
			r.map[r.j][r.i] = r.map_data[r.i];
			r.i++;
		}
		free(r.map_data);
		r.j++;
	}
	close(r.fd_to_read);
	return (r.map);
}
