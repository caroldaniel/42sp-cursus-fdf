/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:36:00 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/30 22:48:45 by cado-car         ###   ########.fr       */
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

void	scale(t_fdf *fdf)
{
	fdf->line->start.x *= fdf->cam->scale_factor;
	fdf->line->start.y *= fdf->cam->scale_factor;
	fdf->line->start.z *= fdf->cam->scale_factor;
	fdf->line->end.x *= fdf->cam->scale_factor;
	fdf->line->end.y *= fdf->cam->scale_factor;
	fdf->line->end.z *= fdf->cam->scale_factor;
}

void	translate(t_fdf *fdf)
{
	fdf->line->start.x += fdf->cam->center_x + fdf->cam->move_x;
	fdf->line->start.y += fdf->cam->center_y + fdf->cam->move_y;
	fdf->line->end.x += fdf->cam->center_x + fdf->cam->move_x;
	fdf->line->end.y += fdf->cam->center_y + fdf->cam->move_y;
}
