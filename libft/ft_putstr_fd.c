/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:17:19 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/18 17:33:50 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_putstr_fd
// Prototype void ft_putstr_fd(char *s, int fd);
// Turn in files -
// Parameters s: The string to output.
// fd: The file descriptor on which to write.
// Return value None
// External functs. write
// Description Outputs the string ’s’ to the given file
// descriptor.

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
