/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 20:21:35 by cado-car          #+#    #+#             */
/*   Updated: 2021/07/30 20:21:35 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <ctype.h>
*	DESCRIPTION
*	The isalpha() function tests for any character for which isupper(3) or 
*	islower(3) is true. The value of the argument must be representable as an 
*	unsigned char or the value of EOF.
*	PARAMETERS
*	#1. The character to test.
*	RETURN VALUES
*	The isalpha() function returns zero if the character tests false and 
*	returns non-zero if the character tests true.
*/

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
