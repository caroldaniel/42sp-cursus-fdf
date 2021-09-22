/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:57:15 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/22 12:38:03 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	***init_coordinates(int width, int depth)
{
	int	i;
	int	j;
	int	***coordinates;

	coordinates = (int ***)malloc(width * sizeof(int **));
	if (!coordinates)
		return (NULL);
	i = 0;
	while (i < width)
	{
		coordinates[i] = (int **)malloc(depth * sizeof(int *));
		if (!coordinates[i])
			return (NULL);
		j = 0;
		while (j < depth)
		{
			coordinates[i][j] = (int *)malloc(2 * sizeof(int));
			if (!coordinates[i][j])
				return (NULL);
			j++;
		}
		i++;
	}
	return (coordinates);
}
