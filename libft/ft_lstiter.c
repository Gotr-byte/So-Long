/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:50:35 by pbiederm          #+#    #+#             */
/*   Updated: 2022/08/08 15:54:58 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	f(void *elem)
// {
// 	int		len;
// 	char	*content;

// 	len = 0;
// 	content = (char *)elem;
// 	while (content[len])
// 	{
// 		content[len++] = 'd';
// 	}
// }
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*point_to_shift;

	point_to_shift = lst;
	while (point_to_shift)
	{
		(*f)(point_to_shift->content);
		point_to_shift = point_to_shift->next;
	}
}

// void	ft_lstiter(t_list *lst, void (*f)(int))
// {
// 	t_list	*point_to_shift;

// 	point_to_shift = lst;
// 	while (point_to_shift)
// 	{
// 		(*f)(point_to_shift->content);
// 		point_to_shift = point_to_shift->next;
// 	}
// }
// int	main(void)
// {
// 	t_list		*elem;
// 	t_list		*elem2;
// 	t_list		*elem3;
// 	t_list		*elem4;
// 	char		*str = ft_strdup("lorem");
// 	char		*str2 = ft_strdup("ipsum");
// 	char		*str3 = ft_strdup("dolor");
// 	char		*str4 = ft_strdup("sit");

// 	elem = ft_lstnew(str);
// 	elem2 = ft_lstnew(str2);
// 	elem3 = ft_lstnew(str3);
// 	elem4 = ft_lstnew(str4);
// 	elem->next = elem2;
// 	elem2->next = elem3;
// 	elem3->next = elem4;

// 	ft_lstiter(elem, &f);

// 	return (0);
// }
