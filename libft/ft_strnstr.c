/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:29:43 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/10 11:36:03 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)h);
	while (i < n && h[i] != '\0' && ft_strlen(needle) <= ft_strlen(h))
	{
		if (ft_strchr(h + i, *(needle + j)))
		{
			while (h[j + i] == needle[j] && needle[j] != '\0' && j + i < n)
			{
				j++;
				if (j == ft_strlen(needle))
					return ((char *)h + i);
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
