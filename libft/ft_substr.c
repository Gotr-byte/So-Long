/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:34:05 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/27 13:47:19 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		subs = (char *)malloc((1) * sizeof(char));
		subs[0] = '\0';
		return (subs);
	}
	else if (len >= ft_strlen(s + start))
		subs = (char *)malloc(ft_strlen(s) - start + 1);
	else
		subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while ((i < len) && (s[start + i] != '\0'))
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
// #include <stdio.h>
// int main()
// {
//   printf("ft_substr: %s", ft_substr("dbad\n", 3, 12));
//   return(0);
//   }
