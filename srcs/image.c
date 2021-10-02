/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:02:49 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/01 23:53:03 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_image(t_image *image, int max_x, int max_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			if (x < max_x - 1)
				bresenham(image, image->coordinates[x][y], \
					image->coordinates[x + 1][y]);
			if (y < max_x - 1)
				bresenham(image, image->coordinates[x][y], \
					image->coordinates[x][y + 1]);
			x++;
		}
		y++;
	}
}

void	bresenham(t_image *image, t_point start, t_point end)
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
			pixel_to_image(image, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
}

void	pixel_to_image(t_image *image, float x, float y, int color)
{
	int	pixel;

	pixel = (int)((y * image->line_bytes) + (x * 4));
	if (pixel < 0 || pixel > (MAX_PIXEL * 4))
		return ;
	if (image->endian == 1)
	{
		image->buffer[pixel + 0] = (color >> 24);
		image->buffer[pixel + 1] = (color >> 16) & 0xff;
		image->buffer[pixel + 2] = (color >> 8) & 0xff;
		image->buffer[pixel + 3] = (color) & 0xff;
	}
	else if (image->endian == 0)
	{
		image->buffer[pixel + 0] = (color) & 0xff;
		image->buffer[pixel + 1] = (color >> 8) & 0xff;
		image->buffer[pixel + 2] = (color >> 16) & 0xff;
		image->buffer[pixel + 3] = (color >> 24);
	}
}

void	clear_image(t_image *image, int max_x, int max_y)
{
	int	size;

	size = max_x * max_y * image->pixel_bits;
	ft_bzero(image->buffer, size);
}
