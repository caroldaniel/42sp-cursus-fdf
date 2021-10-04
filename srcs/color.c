/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:26:21 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/04 08:54:43 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
static t_color	color_init(t_point start, t_point end, int steps);
static int		color_gradient(t_color color, int start_color, int i_color);

int	get_color(t_point start, t_point end, int i_color, int max)
{
	t_color	color;
	
	color = color_init(start, end, max);
	return (color_gradient(color, start.color, i_color));
}

static int	color_gradient(t_color color, int start_color, int i_color)
{
	int		r;
	int		g;
	int		b;
	float	progress;

	progress = (float) i_color / (float)color.steps;
	r = color.delta_r * progress;
	if (r < -255)
		r = 0;
	else if (r > 255)
		r = 255;
	r = r << 16;
	g = color.delta_g * progress;
	if (g < -255)
		g = 0;
	else if (g > 255)
		g = 255;
	g = g << 8;
	b = color.delta_b * progress;
	if (b < -255)
		b = 0;
	else if (b > 255)
		b = 255;
	b = b << 16;
	return (start_color + r + g + b);
}

static t_color	color_init(t_point start, t_point end, int steps)
{
	t_color	color;

	color.steps = steps;
	color.start_r = (C_RED & start.color) >> 16;
	color.start_g = (C_GREEN & start.color) >> 8;
	color.start_b = (C_BLUE & start.color);
	color.end_r = (C_RED & end.color) >> 16;
	color.end_g = (C_GREEN & end.color) >> 8;
	color.end_b = (C_BLUE & end.color);
	color.delta_r = (color.start_r - color.end_r);
	color.delta_g = (color.start_g - color.end_g);
	color.delta_b = (color.start_b - color.end_b);
	return (color);
}
