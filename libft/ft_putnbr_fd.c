/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:54:05 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/19 08:25:23 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	*str;

// 	str = ft_itoa(n);
// 	write(fd, str, ft_strlen(str));
// 	free(str);
// }
#include "libft.h"

static int	count_digit(long long int n)
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

void	ft_putnbr_fd(int n, int fd)
{
	long long int	long_n;
	int				ten_count;
	char			nbr_prnt;

	long_n = (long long int)n;
	if (long_n < 0)
	{
		write (fd, "-", 1);
		long_n = long_n * (-1);
	}
	ten_count = count_digit(long_n);
	while (ten_count--)
	{
		nbr_prnt = long_n / pow_ten(ten_count) + '0';
		write(fd, &nbr_prnt, 1);
		long_n = long_n % pow_ten(ten_count);
	}
}

// int    main(void)
// {
//     int    to_write;
//     int    fd;

//     fd = 1;
//     to_write = -123445;
//     ft_putnbr_fd(to_write, fd);
//     return (0);
// }
