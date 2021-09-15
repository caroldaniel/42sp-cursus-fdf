/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 13:49:27 by cado-car          #+#    #+#             */
/*   Updated: 2021/07/31 14:06:53 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Iterates the list ’lst’ and applies the function ’f’ to the content of each 
*	element. Creates a new list resulting of the successive applications of the 
*	function ’f’. The ’del’ function is used to delete the content of an element 
*	if needed.
*	PARAMETERS
*	#1. The adress of a pointer to an element.
*	#2. The adress of the function used to iterate on the list.
*	#3. The adress of the function used to delete the content of an element if 
*	needed.
*	RETURN VALUES
*	The new list. NULL if the allocation fails.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_map;
	t_list	*elem;

	if (lst == NULL)
		return (NULL);
	lst_map = NULL;
	while (lst != NULL)
	{
		elem = ft_lstnew((*f)(lst->content));
		if (elem == NULL)
			ft_lstclear(&elem, (*del));
		else
			ft_lstadd_back(&lst_map, elem);
		lst = lst->next;
	}
	return (lst_map);
}
