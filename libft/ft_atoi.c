/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:42:12 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/21 10:53:18 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//val[0] - position of index of string without whitespace
//val[1] - value of intefer
//val[2] - positive negative value multiplier
//val[3] - flag that shows there is a valid string with numbers

#include "libft.h"
#include "stdio.h"

static int	ft_wh_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '	' || str[i] == '\t' \
	|| str[i] == '\n' || str[i] == '\v' \
	|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	val[4];

	val[0] = ft_wh_space((char *)str);
	val[1] = 0;
	val[2] = 1;
	val[3] = 0;
	if (str[val[0]] == '-')
		val[2] = -1;
	if (str[val[0]] == '-' || str[val[0]] == '+')
	{
		val[0]++;
		if (str[val[0] + 1] == '-' || str[val[0] + 1] == '+')
			return (0);
	}
	while (((*(str + val[0])) >= 48) && ((*(str + val[0])) <= 57))
	{
		val[1] = 10 * val[1] + (int)(*(str + val[0]) - 48);
		val[3] = 1;
		val[0]++;
	}
	if (val[3] != 0)
		return (val[2] * val[1]);
	return (0);
}
// int    main(void)
// {
// 	char* test_1 = "0";

// 	printf("ft_atoi(%s): %d\n", test_1, ft_atoi(test_1)) ;
// 	printf("atoi(%s): %d\n", test_1, atoi(test_1)) ;
// }
