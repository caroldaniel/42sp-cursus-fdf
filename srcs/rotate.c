/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:02:44 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/01 23:50:27 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
static void	rotate_x(t_point *point, double angle);
static void	rotate_y(t_point *point, double angle);
static void	rotate_z(t_point *point, double angle);

void	rotate(t_fdf *fdf, int max_x, int max_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			rotate_x(&fdf->image->coordinates[x][y], fdf->cam->alpha);
			rotate_y(&fdf->image->coordinates[x][y], fdf->cam->beta);
			rotate_z(&fdf->image->coordinates[x][y], fdf->cam->gamma);
			x++;
		}
		y++;
	}
}

static void	rotate_x(t_point *point, double angle)
{
	point->x = point->x;
	point->y = point->y * cos(angle) - point->z * sin(angle);
	point->z = point->y * sin(angle) + point->z * cos(angle);
}

static void	rotate_y(t_point *point, double angle)
{
	point->x = point->x * cos(angle) + point->z * sin(angle);
	point->y = point->y;
	point->z = point->x * sin(angle) + point->z * cos(angle);

}

static void	rotate_z(t_point *point, double angle)
{
	point->x = point->x * cos(angle) - point->y * sin(angle);
	point->y = point->x * sin(angle) + point->y * cos(angle);
	point->z = point->z;
}
