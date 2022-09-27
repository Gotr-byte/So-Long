/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:30:21 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/21 11:00:22 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(dst_ptr + i) = *(src_ptr + i);
		i++;
	}
	return (dst);
}
// int main(void)
// {
// 	char	*mem;
// 	char	*meme;
// // 	i = 'a';
// 	mem = malloc(20);
// 	meme = malloc(20);
// 	mem = "sas";
// 	meme = "dbc";

// printf("memcpy		%s \n", memcpy(((void *)0), ((void *)0), 3));
// printf("ft_memcpy	%s \n", ft_memcpy(((void *)0), ((void *)0), 3));
// 	free (mem);
// 	free (meme);
// }
// ft_memccpy(dest, "42", '2', 1)
