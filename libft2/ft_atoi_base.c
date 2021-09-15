/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 23:12:43 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/14 22:39:40 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_convert_from_base(char *str, char *base);
int	ft_check_base_error(char *str);

int	ft_atoi_base(char *str, char *base)
{
	int				i;
	int				sign;
	unsigned int	total;

	if (ft_check_base_error(base) == 1)
	{
		i = 0;
		sign = 1;
		total = 0;
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= (-1);
			i++;
		}
		total = ft_convert_from_base(&str[i], base);
		return (total * sign);
	}
	else
		return (0);
}

int	ft_convert_from_base(char *str, char *base)
{
	int	i;
	int	c;
	int	total;

	i = 0;
	total = 0;
	while (ft_strchr(base, str[i]))
	{
		c = 0;
		while (base[c] != str[i])
			c++;
		total *= ft_strlen(base);
		total += c;
		i++;
	}
	return (total);
}

int	ft_check_base_error(char *str)
{
	int	i;
	int	c;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (str[i] == '\0' || len == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-' \
			|| str[i] == ' ' || str[i] == '\n' \
			|| str[i] == '\t' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r')
			return (0);
		c = 1;
		while (str[i + c] != '\0')
		{
			if (str[i + c] == str[i])
				return (0);
			c++;
		}
		i++;
	}
	return (1);
}
