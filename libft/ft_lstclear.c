/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:27:56 by pbiederm          #+#    #+#             */
/*   Updated: 2022/05/25 13:07:13 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstclear
// Prototype void ft_lstclear(t_list **lst, void (*del)(void
// *));
// Turn in files -
// Parameters lst: The address of a pointer to a node.
// del: The address of the function used to delete
// the content of the node.
// Return value None
// External functs. free
// Description Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.

#include "libft.h"

void	ft_lstclear(t_list **lstvoid, void (*del)(void *))
{
	t_list	*point_to_shift;
	t_list	*point_to_rem;

	point_to_shift = *lstvoid;
	while (point_to_shift != NULL)
	{
		point_to_rem = point_to_shift;
		point_to_shift = point_to_shift->next;
		ft_lstdelone (point_to_rem, del);
	}
	*lstvoid = NULL;
}
