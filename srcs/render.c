/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:40:08 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/02 13:18:12 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
static void	render_line(t_fdf *fdf, t_point start, t_point end);
#include <stdio.h>
void	render(t_fdf *fdf)
{
	int	x;
	int	y;

	mlx_clear_window(fdf->mlx, fdf->win);
	clear_image(fdf->image, fdf->map->max_x * fdf->map->max_y);
	y = 0;
	while (y < 1)
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < 1)
		while (x < fdf->map->max_x)
		{
			if (x < fdf->map->max_x - 1)
				render_line(fdf, fdf->map->coordinates[x][y], \
					fdf->map->coordinates[x + 1][y]);
			if (y < fdf->map->max_y - 1)
				render_line(fdf, fdf->map->coordinates[x][y], \
					fdf->map->coordinates[x][y + 1]);
			x++;
		}
		y++;
	}
	// mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image->image, 0, 0);
}

static void	render_line(t_fdf *fdf, t_point start, t_point end)
{
	fdf->image->line = init_line(start, end);
	rotate(fdf->cam, fdf->image->line);
	project(fdf->cam, fdf->image->line);
	transform(fdf->cam, fdf->image->line);
	bresenham(fdf, fdf->image->line->start, fdf->image->line->end);
	free(fdf->image->line);
}
