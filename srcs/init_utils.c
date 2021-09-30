/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:54:44 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/30 11:43:05 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	**init_coordinates(int width, int depth)
{
	t_point	**coordinates;
	int		i;
	int		j;

	coordinates = malloc(width * sizeof(t_point *));
	if (!coordinates)
		return (NULL);
	i = 0;
	while (i < width)
	{
		coordinates[i] = malloc(depth * sizeof(t_point));
		if (!coordinates[i])
			return (NULL);
		j = 0;
		while (j < depth)
		{
			coordinates[i][j] = init_point();
			j++;
		}
		i++;
	}
	return (coordinates);
}
