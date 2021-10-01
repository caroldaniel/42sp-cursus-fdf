/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:36:00 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/30 23:10:59 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	coordinates_to_origin(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_depth)
	{
		x = 0;
		while (x < map->max_width)
		{
			map->coordinates[x][y].x -= map->max_width / 2;
			map->coordinates[x][y].y -= map->max_depth / 2;
			x++;
		}
		y++;
	}
}

// void	project(t_fdf *fdf)
// {
// 	if (fdf->cam->projection == ISOMETRIC)
// 		isometric(fdf->line);
// }

// void	isometric(t_line *line)
// {

// }