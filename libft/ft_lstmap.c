/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:54:57 by pbiederm          #+#    #+#             */
/*   Updated: 2022/08/07 18:00:06 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstmap
// Prototype t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
// void (*del)(void *));
// Turn in files -
// Parameters lst: The address of a pointer to a node.
// f: The address of the function used to iterate on
// the list.
// del: The address of the function used to delete
// the content of a node if needed.
// Return value The new list.
// NULL if the allocation fails.
// External functs. malloc, free
// Description Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.

// #include <stdio.h>
// void	ft_print_result(t_list *elem)
// {
// 	int		len;
// 	len = 0;
// 	while (((char *)elem->content)[len])
// 		len++;
// 	write(1, ((char *)elem->content), len);
// 	write(1, "\n", 1);
// }
// void	*ft_map(void *ct)
// {
// 	int		i;
// 	void	*c;
// 	char	*pouet;
// 	c = ct;
// 	i = -1;
// 	pouet = (char *)c;
// 	while (pouet[++i])
// 		if (pouet[i] == 'o')
// 			pouet[i] = 'a';
// 	return (c);
// }
// void	ft_del(void *content)
// {
// 	free(content);
// }
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	tmp = NULL;
	new = ft_lstnew((*f)(lst->content));
	lst = lst -> next;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
			ft_lstclear(&new, del);
		ft_lstadd_back(&new, tmp);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
	return (new);
}

// int main(void)
// {
// 	t_list		*elem;
// 	t_list		*elem2;
// 	t_list		*elem3;
// 	t_list		*elem4;
// 	t_list		*map;

// 	char	*str = ft_strdup("lorem");
// 	char	*str2 = ft_strdup("ipsum");
// 	char	*str3 = ft_strdup("dolor");
// 	char	*str4 = ft_strdup("sit");

// 	elem = ft_lstnew(str);
// 	elem2 = ft_lstnew(str2);
// 	elem3 = ft_lstnew(str3);
// 	elem4 = ft_lstnew(str4);

// 	elem->next = elem2;
// 	elem2->next = elem3;
// 	elem3->next = elem4;
// 	map = ft_lstmap(elem, ft_map, ft_del);
// 	ft_print_result(map);
// 	ft_print_result(&map[1]);
// 	ft_print_result(&map[2]);
// 	ft_print_result(&map[3]);
// 	// ft_print_result(&map[4]);
// 	return (0);
// }
