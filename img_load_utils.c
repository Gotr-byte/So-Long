/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:14:44 by pbiederm          #+#    #+#             */
/*   Updated: 2022/10/11 14:23:44 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_vars	*img_load_rock(t_vars	*vars)
{
	char	*rock_path;
	int		img_width;
	int		img_height;

	rock_path = "./xpm/rock.xpm";
	vars->rock = mlx_xpm_file_to_image(vars->mlx, \
	rock_path, &img_width, &img_height);
	return (vars);
}
