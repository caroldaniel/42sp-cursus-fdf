/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 20:22:44 by cado-car          #+#    #+#             */
/*   Updated: 2021/07/31 11:22:49 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
*	The memchr() function locates the first occurrence of c (converted to an 
*	unsigned char) in string s.
*	PARAMETERS
*	#1. The pointer in which to check for the occurence of c.
*	#2. The character to check occurence of.
*	#3. The number of bytes to check for any occurence of c in s.
*	RETURN VALUES
*	The memchr() function returns a pointer to the byte located, or NULL if no 
*	such byte exists within n bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;
	size_t			i;

	ch = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)(&str[i]));
		i++;
	}
	return (NULL);
}
