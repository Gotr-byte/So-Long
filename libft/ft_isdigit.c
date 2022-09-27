/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:18:29 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/24 19:17:29 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	int	digit_flag;

	digit_flag = 0;
	if ((48 <= c) && (c <= 57))
		digit_flag = 1;
	return (digit_flag);
}
/*
int	main()
{
	ft_isdigit('a');
	ft_isdigit('B');
	ft_isdigit('3');
	ft_isdigit('9');
	return(0);
}
*/
