/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:48:50 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/25 18:40:28 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isascii(int c)
{
	int		ascii_flag;

	ascii_flag = 0;
	if ((0 <= c) && (c <= 127))
		ascii_flag = 1;
	return (ascii_flag);
}
/*
int	main(void)
{
	ft_isascii('a');
	ft_isascii('B');
	ft_isascii('3');
	ft_isascii('9');
	return (0);
}
*/
