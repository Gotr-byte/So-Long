/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:17:53 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/05 18:40:56 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//pass starting positions
int	check_path(t_vars vars, int x, int y, int num_collectables_tmp)
{
	if (vars.map[y][x + 1] == '0' || vars.map[y][x + 1] == 'C')
		{
			// printf("map[%d][%d]: %d\n", y, x, map[y][x]);
			if(vars.map[y][x] == 'C')
				num_collectables_tmp = num_collectables_tmp + 1;
			vars.map[y][x] = '1';
			printf("map[%d][%d]: %d\n", y, x, vars.map[y][x]);
			num_collectables_tmp = check_path(vars, x + 1, y, num_collectables_tmp);
		}
	if (vars.map[y][x - 1] == '0' || vars.map[y][x - 1] == 'C')
		{
			// printf("map[%d][%d]: %d\n", y, x, map[y][x]);
			if(vars.map[y][x] == 'C')
				num_collectables_tmp = num_collectables_tmp + 1;
			vars.map[y][x] = '1';
			printf("map[%d][%d]: %d\n", y, x, vars.map[y][x]);
			num_collectables_tmp = check_path(vars, x - 1, y, num_collectables_tmp);
		}
	if (vars.map[y + 1][x] == '0' || vars.map[y + 1][x] == 'C')
		{
			// printf("map[%d][%d]: %d\n", y, x, map[y][x]);
			if(vars.map[y][x] == 'C')
				num_collectables_tmp = num_collectables_tmp + 1;
			vars.map[y][x] = '1';
			printf("map[%d][%d]: %d\n", y, x, vars.map[y][x]);
			num_collectables_tmp = check_path(vars, x, y + 1, num_collectables_tmp);
		}
	if (vars.map[y - 1][x] == '0' || vars.map[y - 1][x] == 'C')
		{
			// printf("map[%d][%d]: %d\n", y, x, map[y][x]);
			if(vars.map[y][x] == 'C')
				num_collectables_tmp = num_collectables_tmp + 1;
			vars.map[y][x] = '1';
			printf("map[%d][%d]: %d\n", y, x, vars.map[y][x]);
			num_collectables_tmp = check_path(vars, x, y - 1, num_collectables_tmp);
		}
	printf("map[%d][%d]: %d\n", y, x, vars.map[y][x]);
	if(vars.map[y][x] == 'C')
			num_collectables_tmp = num_collectables_tmp + 1;
	vars.map[y][x] = '1';
	printf("map[%d][%d]: %d\n", y, x, vars.map[y][x]);
	return (num_collectables_tmp);
}
