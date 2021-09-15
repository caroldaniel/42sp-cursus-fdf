/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:57:06 by cado-car          #+#    #+#             */
/*   Updated: 2021/07/31 11:59:26 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a new element. The variable ’content’ 
*	is initialized with the value of the parameter ’content’. The variable 
*	’next’ is initialized to NULL.
*	PARAMETERS
*	#1. The content to create the new element with.
*	RETURN VALUES
*	The new element.
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
