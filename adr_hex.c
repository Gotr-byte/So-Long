/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adr_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:56:12 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/11 17:13:34 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

int	adr_hex(void *p0)
{
	int			i;
	int			ret;
	uintptr_t	p;
	static int	print_flag;
	char		adr_store;

	if (p0 == NULL)
		return (write(1, "0x0", 3 * sizeof(char)));
	p = (uintptr_t)p0;
	print_flag = 0;
	ret = ft_putchar_i('0');
	ret = ret + ft_putchar_i('x');
	i = (sizeof(p) << 3) - 4;
	while (i >= 0)
	{
		adr_store = hex_digit((p >> i) & 0xf);
		if (adr_store > '0' || print_flag > 0)
		{
				ret = ret + ft_putchar_i(adr_store);
				print_flag = 1;
		}
		i -= 4;
	}
	return (ret);
}
