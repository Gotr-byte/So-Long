/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:10:55 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/21 16:14:45 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_ptr;
	char	*src_ptr;
	size_t	counter;

	if (!dst && !src)
		return (NULL);
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	counter = 0;
	if (dst > src)
	{
		while (len--)
			*(dst_ptr + len) = *(src_ptr + len);
	}
	else
	{
		while (counter < len)
		{
			*(dst_ptr + counter) = *(src_ptr + counter);
			counter++;
		}
	}
	return (dst);
}
