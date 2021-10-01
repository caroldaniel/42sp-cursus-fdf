/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:40:08 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/30 23:08:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	render(t_fdf *fdf)
{
	int	x;
	int	y;

	coordinates_to_origin(fdf->map);
	y = -1;
	while (++y < fdf->map->max_depth)
	{
		x = -1;
		while (++x < fdf->map->max_width)
		{
			if (x < fdf->map->max_width - 1)
			{
				fdf->line = init_line(fdf->map->coordinates[x][y], \
					fdf->map->coordinates[x + 1][y]);
				project_line(fdf);
			}
			if (y < fdf->map->max_depth - 1)
			{
				fdf->line = init_line(fdf->map->coordinates[x][y], \
					fdf->map->coordinates[x][y + 1]);
				project_line(fdf);
			}
		}
	}
}

void	project_line(t_fdf *fdf)
{
	// project(fdf);
	scale(fdf);
	// rotate(fdf);
	translate(fdf);
	draw_line(fdf, fdf->line->start, fdf->line->end);
	free(fdf->line);
}

void	draw_line(t_fdf *fdf, t_point start, t_point end)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max = MAX(ABS(x_step), ABS(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if (start.x > 0 && start.y > 0)
			pixel_to_image(fdf, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
}
