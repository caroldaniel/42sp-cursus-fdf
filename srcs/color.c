/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:26:21 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/05 13:47:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
static int	color_gradient(t_color *color, float progress);

int	get_color(t_color *color, int i_line, int line_size)
{
	float	progress;

	progress = (float) i_line / (float) line_size;
	return (color_gradient(color, progress));
}

static int	color_gradient(t_color *color, float progress)
{
	int		r;
	int		g;
	int		b;

	r = color->delta_r * progress;
	if (r < -255)
		r = 0;
	else if (r > 255)
		r = 255;
	r = r << 16;
	g = color->delta_g * progress;
	if (g < -255)
		g = 0;
	else if (g > 255)
		g = 255;
	g = g << 8;
	b = color->delta_b * progress;
	if (b < -255)
		b = 0;
	else if (b > 255)
		b = 255;
	return (color->start_color + r + g + b);
}

t_color	*color_init(t_point start, t_point end)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->start_color = start.color;
	color->start_r = (C_RED & start.color) >> 16;
	color->start_g = (C_GREEN & start.color) >> 8;
	color->start_b = (C_BLUE & start.color);
	color->end_color = end.color;
	color->end_r = (C_RED & end.color) >> 16;
	color->end_g = (C_GREEN & end.color) >> 8;
	color->end_b = (C_BLUE & end.color);
	color->delta_r = (color->end_r - color->start_r);
	color->delta_g = (color->end_g - color->start_g);
	color->delta_b = (color->end_b - color->start_b);
	return (color);
}
