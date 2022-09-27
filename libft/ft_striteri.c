/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:12:02 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/25 18:44:02 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	index = 0;
	if (!s)
		return ;
	while (s[index] != '\0')
	{
		(*f)(index, &s[index]);
		index++;
	}
}
// int    main(void)
// {
//     char    *str;

//     str = malloc(11 * sizeof(char));
//     str = "0000000000";
//     printf("str:                    %s", str);
//     ft_striteri(str, &iter);
//     printf("str after ft_striteri:  %s", str);
// }
