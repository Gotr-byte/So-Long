/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:06:06 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/25 18:41:18 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_itoa
// Prototype char *ft_itoa(int n);
// Turn in files -
// Parameters n: the integer to convert.
// Return value The string representing the integer.
// NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a string
// representing the integer received as
// 2,147,483,647 - max intiger value

#include "libft.h"

static int	count_digit(long long n)
{
	if (n / 10 == 0)
		return (1);
	return (1 + count_digit(n / 10));
}

static int	pow_ten(int n)
{
	int	pow_ten;

	if (n == 0)
	{
		pow_ten = 1;
		return (pow_ten);
	}
	pow_ten = 1;
	while (n--)
		pow_ten = pow_ten * 10;
	return (pow_ten);
}

static char	*append(char *ret_str, long long int long_n, int index)
{
	int				ten_count;

	ten_count = count_digit(long_n);
	while (ten_count--)
	{
		ret_str[index] = long_n / pow_ten(ten_count) + '0';
		long_n = long_n % pow_ten(ten_count);
		index++;
	}
	ret_str[index] = '\0';
	return (ret_str);
}

char	*ft_itoa(int n)
{
	char			*ret_str;
	int				index;
	long long int	long_n;

	long_n = (long long int)n;
	index = 0;
	if (long_n > 2147483647)
		return (NULL);
	if (long_n < -2147483648)
		return (NULL);
	if (long_n < 0)
	{
		ret_str = (char *)malloc((count_digit(long_n) + 2) * sizeof(char));
		if (!ret_str)
			return (NULL);
		ret_str[index] = '-';
		long_n = long_n * -1;
		index++;
	}
	else
		ret_str = (char *)malloc((count_digit(long_n) + 1) * sizeof(char));
	if (!ret_str)
		return (NULL);
	ret_str = append(ret_str, long_n, index);
	return (ret_str);
}
// int    main(void)
// {
//     printf("itoa: %s", ft_itoa(-9));
//     return (0);
// }
