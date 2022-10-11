/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:59:25 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/11 14:16:54 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_strchr_local(const char *s, int c)
{
	int		i;
	char	*h;
	int		t;

	t = ft_strlen(s);
	h = (char *)s;
	i = 0;
	while (i <= t)
	{
		if (*(h + i) == (char)c)
			return (i);
		i++;
	}
	return (0);
}

int	character_pos_y(void)
{
	int		fd_to_read_height;
	int		ret_height;
	char	*tmp;

	fd_to_read_height = open("map.ber", O_RDONLY);
	ret_height = 0;
	while (TRUE)
	{
		tmp = get_next_line(fd_to_read_height);
		if (ft_strchr_local(tmp, 'P'))
		{
			close(fd_to_read_height);
			free(tmp);
			return (ret_height);
		}
		free(tmp);
		ret_height++;
	}
	close(fd_to_read_height);
	return (0);
}

int	character_pos_x(void)
{
	int		fd_to_read_height;
	int		ret_height;
	char	*tmp;

	fd_to_read_height = open("map.ber", O_RDONLY);
	ret_height = 0;
	while (TRUE)
	{
		tmp = get_next_line(fd_to_read_height);
		if (ft_strchr_local(tmp, 'P'))
		{
			close(fd_to_read_height);
			free(tmp);
			return (ft_strchr_local(tmp, 'P'));
		}
		free(tmp);
		ret_height++;
	}
	close(fd_to_read_height);
	return (0);
}
