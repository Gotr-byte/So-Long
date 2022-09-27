/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:35:40 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/16 09:14:31 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s3;
	size_t			incrementator[2];

	s3 = (char *)(malloc(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(s3))
		return (NULL);
	incrementator[0] = 0;
	incrementator[1] = 0;
	while (incrementator[0] < ft_strlen(s1))
	{
		s3[incrementator[0]] = s1[incrementator[0]];
		incrementator[0]++;
	}
	while (incrementator[1] < ft_strlen(s2))
	{
		s3[incrementator[0]] = s2[incrementator[1]];
		incrementator[0]++;
		incrementator[1]++;
	}
		s3[incrementator[0]] = '\0';
	return (s3);
}
/*
int	main(void)
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	char	*strjoin;

	strjoin = ft_strjoin(s1, NULL);
	printf ("s1: %s \n", s1);
	printf ("s2: %s \n", s2);
	printf ("ft_strjoin(s1, s2): %s \n", strjoin);
	s1[0] = '\0';
	printf ("s1: %s \n", s1);
	printf ("s2: %s \n", s2);
	printf ("ft_strjoin(s1, s2): %s \n", strjoin);
}
*/
