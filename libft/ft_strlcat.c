/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:13:26 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/08 16:07:31 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_dst_strlen(const char *s, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0' && i <= dstsize)
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_dst_strlen(dst, dstsize);
	i = 0;
	while (i < src_len && ((dst_len + i + 1) < dstsize))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len > dstsize || !dstsize)
	{
		return (src_len + dstsize);
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
