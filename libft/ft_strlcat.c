/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 20:24:57 by cado-car          #+#    #+#             */
/*   Updated: 2021/07/31 11:27:54 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
*	strlcat() appends string src to the end of dst.  It will append at most 
*	dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless 
*	dstsize is 0 or the original dst string was longer than dstsize (in practice 
*	this should not happen as it means that either dstsize is incorrect or that 
*	dst is not a proper string).
*	PARAMETERS
*	#1. The destiny string in which to concatenate.
*	#2. The source string to concatenate.
*	#3. The total number of bytes in destiny.
*	RETURN VALUES
*	the strlcat() function returns the length of the string it tried to create.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index_src;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	index_src = 0;
	while (src[index_src] != '\0' && dstsize > (len_dst + 1))
	{
		dst[len_dst] = src[index_src];
		index_src++;
		len_dst++;
	}
	dst[len_dst] = '\0';
	return (len_dst + ft_strlen((char *)(&src[index_src])));
}
