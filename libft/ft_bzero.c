/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:17:12 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/27 13:13:29 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*pt;

	pt = s;
	i = 0;
	while (i < n)
	{
			pt[i] = 0;
			i++;
	}
}
/*
int main (void)
{
		char str[50] = "sdgsdgsdfgsdgsdfgsdfgsdfgsdfbs";
		ft_bzero(str, 8*sizeof(char));
		//ft_memset("123456", 'c', 3);
}
*/
