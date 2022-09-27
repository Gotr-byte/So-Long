/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:17:02 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/03 10:42:21 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;
	size_t			i;

	i = 0;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*(t1 + i) != *(t2 + i))
			return ((*(t1 + i)) - (*(t2 + i)));
		i++;
	}
	return (0);
}
/*
int main()
{
	printf( "ft_memcmp: %d\n", ft_memcmp("", "", 4));
	printf( "memcmp: %d\n", memcmp("", "", 4));
	printf( "ft_memcmp: %d\n", ft_memcmp("t\200", "t\0", 2));
	printf( "memcmp: %d\n", memcmp("t\200", "t\0", 2));

}
*/
