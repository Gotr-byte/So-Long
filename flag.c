/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:14:40 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/11 17:27:48 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prt_par_xx(unsigned int prt)
{
	char	*str;
	int		i;

	str = ft_itoa_xx(prt);
	i = ft_putstr_i(str);
	free(str);
	return (i);
}

int	prt_par_x(unsigned int prt)
{
	char	*str;
	int		i;

	str = ft_itoa_x(prt);
	i = ft_putstr_i(str);
	free(str);
	return (i);
}

int	prt_par_lu(unsigned int prt)
{
	char	*str;
	int		i;

	str = ft_itoa_lu(prt);
	i = ft_putstr_i(str);
	free(str);
	return (i);
}

int	di(int prt)
{
	char	*str;
	int		i;

	str = ft_itoa(prt);
	i = ft_putstr_i(str);
	free(str);
	return (i);
}

int	flag(va_list arg, char flag)
{
	if (flag == 'u')
		return (prt_par_lu(va_arg(arg, unsigned int)));
	else if (flag == 'x')
		return (prt_par_x(va_arg(arg, unsigned int)));
	else if (flag == 'X')
		return (prt_par_xx(va_arg(arg, unsigned int)));
	else if (flag == 'p')
		return (adr_hex(va_arg(arg, void *)));
	else if ((flag == 'd' || flag == 'i' ))
		return (di(va_arg(arg, int)));
	else if (flag == 'c')
		return (ft_putchar_i(va_arg(arg, int)));
	else if (flag == 's')
		return (ft_putstr_i(va_arg(arg, char *)));
	else if (flag == '%')
		return (write(1, "%", sizeof(char)));
	return (0);
}
