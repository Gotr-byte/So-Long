/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:45:33 by pbiederm          #+#    #+#             */
/*   Updated: 2022/08/08 15:48:01 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Prototype t_list *ft_lstnew(void *content);
// Turn in files -
// Parameters content: The content to create the node with.
// Return value The new node
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’. The variable
// ’next’ is initialized to NULL.

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	if (!content)
		tmp->content = NULL;
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}
