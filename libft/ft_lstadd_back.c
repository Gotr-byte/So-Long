/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:35:56 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/25 18:41:23 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstadd_back
// Prototype void ft_lstadd_back(t_list **lst, t_list *new);
// Turn in files -
// Parameters lst: The address of a pointer to the first link of
// a list.
// new: The address of a pointer to the node to be
// added to the list.
// Return value None
// External functs. None
// Description Adds the node ’new’ at the end of the list.
// void ft_print_result(t_list *elem)
// {
// 	int len;

// 	len = 0;
// 	while (((char *)elem->content)[len])
// 		len++;
// 	write(1, elem->content, len);
// 	write(1, "\n", 1);
// }	
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last)
	{
		if (last->next == NULL)
			break ;
		last = last->next;
	}
	last->next = new;
	return ;
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
// 	str = ft_strdup("ever");
// 	str_1 = ft_strdup("roaddd");
// 	str_2 = ft_strdup("the");
// 	str_3 = ft_strdup("goes");
// 	str_4 = ft_strdup("on");
// 	node = ft_lstnew(str);
// 	node_1 = ft_lstnew(str_1);
// 	node_1 = ft_lstnew(str_2);
// 	node_1 = ft_lstnew(str_3);
// 	node_1 = ft_lstnew(str_4);
// 	temp = NULL;
// 	ft_lstadd_back(&temp, node);
// 	ft_lstadd_back(&temp, node_1);
// 	ft_lstadd_back(&temp, node_2);
// 	ft_lstadd_back(&temp, node_3);
// 	ft_lstadd_back(&temp, node_4);
// 	while (temp)
// 	{
// 	ft_print_result(temp);
// 	temp = temp->next;
// 	}
// 	return (0);
// }
