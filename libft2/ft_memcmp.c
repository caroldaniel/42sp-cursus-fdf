/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 20:22:51 by cado-car          #+#    #+#             */
/*   Updated: 2021/07/31 11:22:43 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
*	The memcmp() function compares byte string s1 against byte string s2.  
*	Both strings are assumed to be n bytes long.
*	PARAMETERS
*	#1. The first pointer to compare.
*	#2. The second pointer to compare.
*	#3. The number of bytes to compare the two pointers.
*	RETURN VALUES
*	The memcmp() function returns zero if the two strings are identical, 
*	otherwise returns the difference between the first two differing bytes 
*	(treated as unsigned char values, so that `\200' is greater than `\0', for 
*	example).  Zero-length strings are always identical.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		else
			i++;
	}
	return (0);
}
