/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:17:53 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/07 19:46:11 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//add colectable count, change value to 1
static int	move_reg(t_vars *vars, int x, int y)
{
	if (vars->n[y][x] == 'C')
	{
		vars->n[y][x] = '1';
		return (1);
	}
	vars->n[y][x] = '1';
	return (0);
}

static int	move_reg_exit(t_vars *vars, int x, int y)
{
	if (vars->o[y][x] == 'E')
	{
		vars->o[y][x] = '1';
		return (1);
	}
	vars->o[y][x] = '1';
	return (0);
}

//pass starting positions
int	check_path(t_vars *v, int x, int y, int num_collect_tmp)
{
	if (v->n[y][x + 1] == '0' || v->n[y][x + 1] == 'C' || v->n[y][x + 1] == 'E')
	{
		num_collect_tmp = num_collect_tmp + move_reg(v, x, y);
		num_collect_tmp = check_path(v, x + 1, y, num_collect_tmp);
	}
	if (v->n[y][x - 1] == '0' || v->n[y][x - 1] == 'C' || v->n[y][x + 1] == 'E')
	{
		num_collect_tmp = num_collect_tmp + move_reg(v, x, y);
		num_collect_tmp = check_path(v, x - 1, y, num_collect_tmp);
	}
	if (v->n[y + 1][x] == '0' || v->n[y + 1][x] == 'C'|| v->n[y][x + 1] == 'E')
	{
		num_collect_tmp = num_collect_tmp + move_reg(v, x, y);
		num_collect_tmp = check_path(v, x, y + 1, num_collect_tmp);
	}
	if (v->n[y - 1][x] == '0' || v->n[y - 1][x] == 'C'|| v->n[y][x + 1] == 'E')
	{
		num_collect_tmp = num_collect_tmp + move_reg(v, x, y);
		num_collect_tmp = check_path(v, x, y - 1, num_collect_tmp);
	}
	num_collect_tmp = num_collect_tmp + move_reg(v, x, y);
	return (num_collect_tmp);
}

// int	go_east(t_vars vars, int x, int y, int num_exit)
// {
// }

int	check_path_exit(t_vars *v, int x, int y, int num_exit)
{
	if (v->o[y][x + 1] == '0' || v->o[y][x + 1] == 'C' || v->o[y][x + 1] == 'E')
	{
		num_exit = num_exit + move_reg_exit(v, x, y);
		num_exit = check_path_exit(v, x + 1, y, num_exit);
	}
	if (v->o[y][x - 1] == '0' || v->o[y][x - 1] == 'C' || v->o[y][x - 1] == 'E')
	{
		num_exit = num_exit + move_reg_exit(v, x, y);
		num_exit = check_path_exit(v, x - 1, y, num_exit);
	}
	if (v->o[y + 1][x] == '0' || v->m[y + 1][x] == 'C' || v->o[y + 1][x] == 'E')
	{
		num_exit = num_exit + move_reg_exit(v, x, y);
		num_exit = check_path_exit(v, x, y + 1, num_exit);
	}
	if (v->o[y - 1][x] == '0' || v->m[y - 1][x] == 'C' || v->o[y - 1][x] == 'E')
	{
		num_exit = num_exit + move_reg_exit(v, x, y);
		num_exit = check_path_exit(v, x, y - 1, num_exit);
	}
	num_exit = num_exit + move_reg_exit(v, x, y);
	return (num_exit);
}
