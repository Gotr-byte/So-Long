/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:55:24 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/04 14:44:15 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*h;
	size_t	t;

	t = ft_strlen(s);
	h = (char *)s;
	i = 0;
	while (i <= t)
	{
		if (*(h + i) == (char)c)
			return (h + i);
		i++;
	}
	return (0);
}
