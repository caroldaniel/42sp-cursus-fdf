/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:49:11 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/20 14:31:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->coordinates = NULL;
	fdf->max_width = 0;
	fdf->max_depth = 0;
	fdf->max_height = 0;
	fdf->min_height = 0;
	return (fdf);
}

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

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = NULL;
	data->win = NULL;
	
	return (data);
}
