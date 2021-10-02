/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:02:44 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/02 16:28:15 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
static void	rotate_x(t_line *line, double angle);
static void	rotate_y(t_line *line, double angle);
static void	rotate_z(t_line *line, double angle);

void	rotate(t_cam *cam, t_line *line)
{
	rotate_x(line, cam->alpha);
	rotate_y(line, cam->beta);
	rotate_z(line, cam->gamma);
}

static void	rotate_x(t_line *line, double angle)
{
	t_point	new_start;
	t_point	new_end;

	new_start.y = line->start.y * cos(angle) - line->start.z * sin(angle);
	new_start.z = line->start.y * sin(angle) + line->start.z * cos(angle);
	line->start.y = new_start.y;
	line->start.z = new_start.z;
	new_end.y = line->end.y * cos(angle) - line->end.z * sin(angle);
	new_end.z = line->end.y * sin(angle) + line->end.z * cos(angle);
	line->end.y = new_end.y;
	line->end.z = new_end.z;
}

static void	rotate_y(t_line *line, double angle)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = line->start.x * cos(angle) + line->start.z * sin(angle);
	new_start.z = -line->start.x * sin(angle) + line->start.z * cos(angle);
	line->start.x = new_start.x;
	line->start.z = new_start.z;
	new_end.x = line->end.x * cos(angle) + line->end.z * sin(angle);
	new_end.z = -line->end.x * sin(angle) + line->end.z * cos(angle);
	line->end.x = new_end.x;
	line->end.z = new_end.z;
}

static void	rotate_z(t_line *line, double angle)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = line->start.x * cos(angle) - line->start.y * sin(angle);
	new_start.y = line->start.x * sin(angle) + line->start.y * cos(angle);
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = line->end.x * cos(angle) - line->end.y * sin(angle);
	new_end.y = line->end.x * sin(angle) + line->end.y * cos(angle);
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}
