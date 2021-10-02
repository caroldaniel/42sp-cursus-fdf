/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 22:44:08 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/01 23:30:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
static void	scale(t_point *point, int scale_factor);
static void	translate(t_point *point, int move_x, int move_y);

void	transform(t_fdf *fdf, int max_x, int max_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			scale(&fdf->image->coordinates[x][y], fdf->cam->scale_factor);
			translate(&fdf->image->coordinates[x][y], fdf->cam->move_x, fdf->cam->move_y);
			x++;
		}
		y++;
	}
}

static void	scale(t_point *point, int scale_factor)
{
	point->x *= scale_factor;
	point->y *= scale_factor;
}

static void	translate(t_point *point, int move_x, int move_y)
{
	point->x += move_x;
	point->y += move_y;
}
