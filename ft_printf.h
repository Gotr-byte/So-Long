/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:09:12 by pbiederm          #+#    #+#             */
/*   Updated: 2022/07/09 11:09:12 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "./libft/libft.h"

char	*ft_itoa_xx(unsigned long n);
int		ft_printf(const char *prt, ...);
char	*ft_itoa_x(unsigned long n);
char	*ft_itoa_lu(unsigned long n);
int		ft_putstr_i(char *str);
int		adr_hex(void *p0);
int		ft_putchar_i(char c);
int		flag(va_list arg, char flag);
#endif