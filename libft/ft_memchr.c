/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:52:00 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/04 12:53:49 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*h;
	unsigned char	*v;
	unsigned char	uc;
	char			flag;

	uc = (unsigned char)(c);
	h = (unsigned char *)s;
	i = 0;
	flag = 0;
	while (i < n)
	{
		if (*(h + i) == uc)
		{
			v = (h + i);
			flag = 1;
			break ;
		}
		if (flag == 1)
			break ;
		i++;
	}
	if (flag == 1)
		return (v);
	return (NULL);
}
/*
int main()
{
	// int *ptr;
	// int *ptr_1;
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	
	// ft_memchr("bonjour", 'o', 7);
	// char str[100] = "bonjour";
	// ptr = ft_memchr(str, 'o', 7); 
	// ptr_1 = memchr (str, 'o', 7);
	// printf ("ft_memchr: %p\n", ptr);
	// printf ("ft_memchr: %p\n", ptr_1);
	printf ("trip check ft_memchr: %p\n", ft_memchr(s, 2 + 256, 3));
	printf ("trip check memchr: %p\n", memchr(s, 2 + 256, 3));
}
*/
