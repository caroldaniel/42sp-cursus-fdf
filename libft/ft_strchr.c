/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 20:24:33 by cado-car          #+#    #+#             */
/*   Updated: 2021/07/31 11:25:15 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
*	The strchr() function locates the first occurrence of c (converted to a 
*	char) in the string pointed to by s. The terminating null character is 
*	considered to be part of the string; therefore if c is `\0', the functions 
*	locate the terminating `\0'.
*	PARAMETERS
*	#1. The string in which to checks for the occurence of c.
*	#2. The character to check the occurence of.
*	RETURN VALUES
*	The function strchr() returns a pointer to the located 
*	character, or NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)(&s[i]));
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
