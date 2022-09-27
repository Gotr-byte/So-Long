/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:44:30 by pbiederm          #+#    #+#             */
/*   Updated: 2022/04/25 16:53:15 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	int	alnum_flag;

	alnum_flag = 0;
	if ((65 <= c) && (c <= 90))
		alnum_flag = 1;
	if ((97 <= c) && c <= 122)
		alnum_flag = 2;
	if ((48 <= c) && (c <= 57))
		alnum_flag = 3;
	return (alnum_flag);
}
/*
int	main(void)
{
	ft_isalnum('a');
	ft_isalnum('B');
	ft_isalnum('3');
	ft_isalnum('9');
	return(0);
}
*/
