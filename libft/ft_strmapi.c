/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:07:15 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/25 18:44:33 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_strmapi
// Prototype char *ft_strmapi(char const *s, char (*f)(unsigned
// int, char));
// Turn in files -
// Parameters s: The string on which to iterate.
// f: The function to apply to each character.
// Return value The string created from the successive applications
// of ’f’.
// Returns NULL if the allocation fails.
// External functs. malloc
// Description Applies the function ’f’ to each character of the
// string ’s’, and passing its index as first argument
// to create a new string (with malloc(3)) resulting
// from successive applications of ’f’.
// static char make_f (unsigned int index, char f)
// {
// 	f = f + index;
// 	return (f);
// }

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*t;
	int					t_index;
	unsigned int		index;

	index = 0;
	t_index = 0;
	t = (char *)s;
	t = (char *)malloc(ft_strlen(s) + 1);
	if (!t)
		return (NULL);
	while (s[index] != '\0')
	{
		t[t_index] = f(index, s[index]);
		index++;
		t_index++;
	}
	t[t_index] = '\0';
	return (t);
}

// int	main(void)
// {
// 	char	*str;

// 	str = malloc (4);
// 	str = "abc";
// 	printf("ft_strmapi: %s", ft_strmapi(str, &make_f));
// 	return (0);
// }