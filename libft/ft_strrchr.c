/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:07:27 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/26 12:20:21 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*h;
	char	*v;
	size_t	t;

	h = (char *)s;
	t = ft_strlen(s) + 1;
	while ((t-- + 1) > 0)
	{
		if (*(h + t) == (char)c)
		{
			v = (h + t);
			return (v);
		}
		if (t == 0)
			return (NULL);
	}
	return (NULL);
}
/*
int main(void)
{
	char *v;
	char *p;
	// char aac[100] = "aacaac";
	
	str2[] = "bonjour";
	
	
	v = ft_strrchr(str2, 's');
	p = strrchr(str2, 's');
	printf ("ft_strrchr: %p\n", v);
	printf ("strrchr: %p\n", p);	
	
	// v = ft_strrchr(aac, 'c');
	// p = strrchr(aac, 'c');
	// printf ("ft_strrchr: %p\n", v);
	// printf ("strrchr: %p\n", p);	
	// ft_strrchr(s, 0)
	// check(ft_strrchr(s, 'l') == s + 8); showLeaks();
	//  check(ft_strrchr(s2, 'l') == s2 + 9); showLeaks();
	// char s[] = "tripouille";
	// char s2[] = "ltripouiel";
	// ft_strrchr(str2, 's')
}
*/
