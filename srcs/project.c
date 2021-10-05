/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:36:00 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/04 23:17:43 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
static void	isometric(t_line *line);
static void	perspective(t_line *line);

void	project(t_cam *cam, t_line *line)
{
	if (cam->projection == ISOMETRIC)
		isometric(line);
	else if (cam->projection == PERSPECTIVE)
		perspective(line);
	else if (cam->projection == TOP)
		return ;
}

static void	isometric(t_line *line)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = (line->start.x - line->start.y) * cos(ANG_30);
	new_start.y = (line->start.x + line->start.y) * sin(ANG_30) - \
		line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = (line->end.x - line->end.y) * cos(ANG_30);
	new_end.y = (line->end.x + line->end.y) * sin(ANG_30) - line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

static void	perspective(t_line *line)
{
	t_point	new_start;
	t_point	new_end;
	double	z;

	rotate_x(line, 3 * -ANG_45);
	z = line->start.z + line->transform_z;
	new_start.x = line->start.x / z;
	new_start.y = line->start.y / z;
	line->start.x = new_start.x;
	line->start.y = -new_start.y;
	z = line->end.z + line->transform_z;
	new_end.x = line->end.x / z;
	new_end.y = line->end.y / z;
	line->end.x = new_end.x;
	line->end.y = -new_end.y;
	scale(line, line->transform_z);
}
