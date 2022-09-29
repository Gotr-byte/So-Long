/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:47:21 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/29 14:16:43 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include "./mlx/mlx.h"

typedef struct s_grid
{
	int	data;
	int	pos_x;
	int pos_y;
	struct s_grid	*up;
	struct s_grid	*right;
	struct s_grid	*down;
	struct s_grid	*left;
}	t_grid;

#endif