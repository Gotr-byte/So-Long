/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:20:35 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/23 13:18:54 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstlast
// Prototype t_list *ft_lstlast(t_list *lst);
// Turn in files -
// Parameters lst: The beginning of the list.
// Return value Last node of the list
// External functs. None
// Description Returns the last node of the list.

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
// int	main(void)
// {
// 	t_list	*temp;
// 	t_list	*node;
// 	t_list	*node_1;
// 	t_list	*node_2;
// 	t_list	*node_3;
// 	t_list	*node_4;
// 	char	*str;
// 	char	*str_1;
// 	char	*str_2;
// 	char	*str_3;
// 	char	*str_4;

// 	str = NULL;
// 	str_1 = ft_strdup("roaddd");
// 	str_2 = ft_strdup("ever");
// 	str_3 = ft_strdup("goes");
// 	str_4 = ft_strdup("on");

// 	node = ft_lstnew(str);
// 	node_1 = ft_lstnew(str_1);
// 	node_2 = ft_lstnew(str_2);
// 	node_3 = ft_lstnew(str_3);
// 	node_4 = ft_lstnew(str_4);

// 	node->next = node_1;
// 	node_1->next = node_3;
// 	node_2->next = node_3;
// 	node_3->next = node_4;
// 	temp = ft_lstlast(node);
// }
