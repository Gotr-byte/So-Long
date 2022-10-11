/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:29:07 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/11 17:17:06 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *prt, ...)
{
	va_list			arg;
	int				n;
	int				ret;

	n = 0;
	ret = 0;
	va_start(arg, prt);
	while (prt[n] != '\0')
	{
		if (prt[n] != '%')
			ret = ret + write (1, &prt[n], sizeof(char));
		else if (prt[n++] == '%')
			ret = ret + flag(arg, prt[n]);
		n++;
	}
	va_end(arg);
	return (ret);
}

// int	main(void)
// {
// 	char	*bline;
// 	void	*melkor;
// 	int		tez;
// 	int		minne;

// 	bline = "blineeeeer";
// 	melkor = malloc(sizeof(melkor));
// 	melkor = &tez;
// 	tez = ft_printf ("%%Eldrich blast %s %d %i %u %c %p %x %X%%\n"
// , "is cast and deals", 24, -21, 111, 'c', melkor, 111, 111);
// 	minne = printf ("%%Eldrich blast %s %d %i %u %c %p %x %X%%\n"
// , "is cast and deals", 24, -21, 111, 'c', melkor, 111, 111);
// 	// tez = ft_printf ("NULL %s NULL\n", NULL);
// 	// minne = printf ("NULL %s NULL\n", NULL);

// 	// printf ("ft_printf: %d\n", tez);
// 	// printf ("printf: %d\n", minne);
// }
