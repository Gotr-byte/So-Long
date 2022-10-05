/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:17:53 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/05 20:01:42 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//pass starting positions
int	check_path(t_vars vars, int x, int y, int num_collectables_tmp)
{
	if (vars.map[y][x + 1] == '0' || vars.map[y][x + 1] == 'C')
		{
			if(vars.map[y][x] == 'C')
				num_collectables_tmp = num_collectables_tmp + 1;
			vars.map[y][x] = '1';
			num_collectables_tmp = check_path(vars, x + 1, y, num_collectables_tmp);
		}
	if (vars.map[y][x - 1] == '0' || vars.map[y][x - 1] == 'C')
		{
			if(vars.map[y][x] == 'C')
				num_collectables_tmp = num_collectables_tmp + 1;
			vars.map[y][x] = '1';
			num_collectables_tmp = check_path(vars, x - 1, y, num_collectables_tmp);
		}
	if (vars.map[y + 1][x] == '0' || vars.map[y + 1][x] == 'C')
		{
			if(vars.map[y][x] == 'C')
				num_collectables_tmp = num_collectables_tmp + 1;
			vars.map[y][x] = '1';
			num_collectables_tmp = check_path(vars, x, y + 1, num_collectables_tmp);
		}
	if (vars.map[y - 1][x] == '0' || vars.map[y - 1][x] == 'C')
		{
			if(vars.map[y][x] == 'C')
				num_collectables_tmp = num_collectables_tmp + 1;
			vars.map[y][x] = '1';
			num_collectables_tmp = check_path(vars, x, y - 1, num_collectables_tmp);
		}
	if(vars.map[y][x] == 'C')
			num_collectables_tmp = num_collectables_tmp + 1;
	vars.map[y][x] = '1';
	return (num_collectables_tmp);
}

int	check_path_exit(t_vars vars, int x, int y, int num_exit)
{
	if (vars.map[y][x + 1] == '0' || vars.map[y][x + 1] == 'C' || vars.map[y][x + 1] == 'E')
		{
			printf("map[%d][%d]: %d", y, x, vars.map[y][x]);
			if(vars.map[y][x] == 'E')
				num_exit = num_exit + 1;
			vars.map[y][x] = '1';
			printf("map[%d][%d]: %d", y, x, vars.map[y][x]);
			num_exit = check_path_exit(vars, x + 1, y, num_exit);
		}
	if (vars.map[y][x - 1] == '0' || vars.map[y][x - 1] == 'C' || vars.map[y][x - 1] == 'E')
		{
			printf("map[%d][%d]: %d", y, x, vars.map[y][x]);
			if(vars.map[y][x] == 'E')
				num_exit = num_exit + 1;
			vars.map[y][x] = '1';
			printf("map[%d][%d]: %d", y, x, vars.map[y][x]);
			num_exit = check_path_exit(vars, x - 1, y, num_exit);
		}
	if (vars.map[y + 1][x] == '0' || vars.map[y + 1][x] == 'C' || vars.map[y + 1][x] == 'E') 
		{
			printf("map[%d][%d]: %d", y, x, vars.map[y][x]);
			if(vars.map[y][x] == 'E')
				num_exit = num_exit + 1;
			vars.map[y][x] = '1';
			printf("map[%d][%d]: %d", y, x, vars.map[y][x]);
			num_exit = check_path_exit(vars, x, y + 1, num_exit);
		}
	if (vars.map[y - 1][x] == '0' || vars.map[y - 1][x] == 'C' || vars.map[y - 1][x] == 'E')
		{
			printf("map[%d][%d]: %d", y, x, vars.map[y][x]);
			if(vars.map[y][x] == 'E')
				num_exit = num_exit + 1;
			vars.map[y][x] = '1';
			printf("map[%d][%d]: %d", y, x, vars.map[y][x]);
			num_exit = check_path_exit(vars, x, y - 1, num_exit);
		}
	printf("map[%d][%d]: %d", y, x, vars.map[y][x]);
	if(vars.map[y][x] == 'E')
			num_exit = num_exit + 1;
	vars.map[y][x] = '1';
	printf("map[%d][%d]: %d", y, x, vars.map[y][x]);
	return (num_exit);
}

