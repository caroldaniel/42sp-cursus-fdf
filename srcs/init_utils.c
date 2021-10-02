/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:54:44 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/01 23:53:10 by cado-car         ###   ########.fr       */
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
			coordinates[i][j].x = 0;
			coordinates[i][j].y = 0;
			coordinates[i][j].z = 0;
			coordinates[i][j].color = 0;
			j++;
		}
		i++;
	}
	return (coordinates);
}

void	center_to_origin(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			map->coordinates[x][y].x -= map->max_x / 2;
			map->coordinates[x][y].y -= map->max_y / 2;
			x++;
		}
		y++;
	}
}

float	scale_to_fit(t_map *map)
{
	float	scale_x;
	float	scale_y;

	scale_x = WINDOW_WIDTH / map->max_x;
	scale_y = WINDOW_HEIGHT / map->max_y;
	return (MIN(scale_x, scale_y));
}

void	transfer_coordinates(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			fdf->map->coordinates[x][y].x = fdf->image->coordinates[x][y].x;
			fdf->map->coordinates[x][y].y = fdf->image->coordinates[x][y].y;
			fdf->map->coordinates[x][y].z = fdf->image->coordinates[x][y].z;
			fdf->map->coordinates[x][y].color = fdf->image->coordinates[x][y].color;
			x++;
		}
		y++;
	}
}
