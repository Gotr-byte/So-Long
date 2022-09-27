/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:58:23 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/25 18:40:40 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	int	isprint_flag;

	isprint_flag = 0;
	if ((32 <= c) && (c <= 126))
		isprint_flag = 1;
	return (isprint_flag);
}
/*
int	main(void)
{
	ft_isprint('a');
	ft_isprint('B');
	ft_isprint('3');
	ft_isprint('9');
	return(0);
}
*/
