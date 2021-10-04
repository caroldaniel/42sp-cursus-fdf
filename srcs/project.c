/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:36:00 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/03 23:07:28 by cado-car         ###   ########.fr       */
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

	if (line->start.y != 0)
	{
		new_start.x = line->start.x / line->start.y;
		new_start.y = line->start.z / line->start.y;
	}
	else
	{
		new_start.x = line->start.x;
		new_start.y = line->start.z;	
	}
	if (line->end.y != 0)
	{
		new_end.x = line->end.x / line->end.y;
		new_end.y = line->end.z / line->end.y;
	}
	else
	{
		new_end.x = line->start.x;
		new_end.y = line->start.z;		
	}
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}
