/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:14:44 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/10 15:29:55 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const	char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && *src != '\0')
		{
			*dst = *src;
			dst++;
			src++;
			i++;
		}
		*dst = '\0';
	}	
	return (j);
}
/*
int main()
{
	char *string;
	char string1[15];
	
	// string = malloc(15);	
	strlcpy(string, "12345678901234", 15);
	printf ("string: %s\n", string);
	// printf("strlcpy: %zu\n", strlcpy(string, "", 15));
	printf("ft_strlcpy: %zu\n",ft_strlcpy(string, "", 15) );
	printf ("string: %s\n", string);
}
*/
