/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:19:57 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/25 18:43:49 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	char	*t1;
	char	*t2;
	int		i;
	int		len_t1;
	int		len_t2;

	i = 0;
	t1 = (char *)s1;
	t2 = (char *)s2;
	len_t1 = ft_strlen(t1);
	len_t2 = ft_strlen(t2);
	while (i <= len_t1 || i <= len_t2)
	{
		if ((unsigned char)*(t1 + i) > (unsigned char)*(t2 + i))
			return (1);
		if ((unsigned char)*(t1 + i) < (unsigned char)*(t2 + i))
			return (-1);
		i++;
	}
	return (0);
}
// int main()
// {
// 	printf( "strcmp: %d\n", strcmp("test\200", "test\0"));
// 	printf( "ft_strcmp: %d\n", ft_strcmp("test\200", "test\0"));
// 	//ft_strncmp("test\200", "test\0", 6)
// }
