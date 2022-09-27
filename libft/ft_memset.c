/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:06:34 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/26 13:40:17 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*(ptr + i) = c;
		i++;
	}
	return (b);
}
/*
	int main (void)
	{
		char str[50] = "sdgsdgsdfgsdgsdfgsdfgsdfgsdfbs";
		ft_memset(str, '.', 8*sizeof(char));
		//ft_memset("123456", 'c', 3);
	}
*/
