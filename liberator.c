/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:51:23 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/03 17:51:38 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	liberator(int	**map, int map_height)
{
	int	j;

	j = 0;
	while (j < map_height)
	{
		free(map[j]);
		j++;
	}
}
