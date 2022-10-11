/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:47:59 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/11 17:26:09 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit_lu(size_t n)
{
	if (n / 10 == 0)
		return (1);
	return (1 + count_digit_lu(n / 10));
}

static int	pow_ten_lu(size_t n)
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

static char	*append_lu(char *ret_str, size_t long_n, size_t index)
{
	size_t				ten_count;

	ten_count = count_digit_lu(long_n);
	while (ten_count--)
	{
		ret_str[index] = long_n / pow_ten_lu(ten_count) + '0';
		long_n = long_n % pow_ten_lu(ten_count);
		index++;
	}
	ret_str[index] = '\0';
	return (ret_str);
}

char	*ft_itoa_lu(unsigned long n)
{
	char			*ret_str;
	size_t			index;
	size_t			long_n;

	long_n = (size_t)n;
	index = 0;
	if (long_n > 4294967295)
		return (NULL);
	else
		ret_str = (char *)malloc((count_digit_lu(long_n) + 1) * sizeof(char));
	if (!ret_str)
		return (NULL);
	ret_str = append_lu(ret_str, long_n, index);
	return (ret_str);
}
