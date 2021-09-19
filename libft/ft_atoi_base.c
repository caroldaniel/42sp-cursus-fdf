/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 23:12:43 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/19 00:56:33 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	The atoi_base() function converts the initial portion of the string pointed 
*	to by str to its int representation considering a given base.
*	PARAMETERS
*	#1. The string to convert to integer.
*	#2. The base in which to convert the string from, all lowercased.
*	RETURN VALUES
*	The atoi_base() function returns its converted int representation.
*/

int	ft_convert_from_base(char *str, char *base);
int	ft_check_base_error(char *str);

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		total;
	size_t	i;

	if (!ft_check_base_error(base))
		return (0);
	sign = 1;
	total = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	if (str[i] == '0')
	{
		i++;
		if (str[i] == 'x')
			i++;
	}
	total = ft_convert_from_base(&str[i], base);
	return (total * sign);
}

int	ft_convert_from_base(char *str, char *base)
{
	size_t	i;
	size_t	c;
	int		total;
	int		base_len;

	i = 0;
	total = 0;
	base_len = ft_strlen(base);
	while (str[i] && ft_strchr(base, ft_tolower(str[i])))
	{
		c = 0;
		while (base[c] != ft_tolower(str[i]) && base[c])
			c++;
		total = (total * base_len) + c;
		i++;
	}
	return (total);
}

int	ft_check_base_error(char *str)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[i])
	{
		if (!ft_isprint(str[i]))
			return (0);
		c = 1;
		while (str[i + c])
		{
			if (str[i + c] == str[i])
				return (0);
			c++;
		}
		i++;
	}
	return (1);
}
