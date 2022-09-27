/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:05:20 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/25 18:43:55 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	str_size;

	str_size = ft_strlen(s1) + 1;
	s2 = (char *) malloc((str_size) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, str_size);
	return (s2);
}
/*
int	main(void)
{	
	char *s2;

	s2 = ft_strdup("nice and sunny weather");
	free(s2);
}
*/
