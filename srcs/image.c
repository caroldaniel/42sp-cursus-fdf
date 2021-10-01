/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:02:49 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/30 19:44:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	pixel_to_image(t_fdf *fdf, float x, float y, int color)
{
	int	pixel;

	if (fdf->image->pixel_bits != 32)
		color = mlx_get_color_value(fdf->mlx, color);
	pixel = (int)((y * fdf->image->line_bytes) + (x * 4));
	if (pixel < 0 || pixel > (MAX_PIXEL * 4))
		return ;
	if (fdf->image->endian == 1)
	{
		fdf->image->buffer[pixel + 0] = (color >> 24);
		fdf->image->buffer[pixel + 1] = (color >> 16) & 0xff;
		fdf->image->buffer[pixel + 2] = (color >> 8) & 0xff;
		fdf->image->buffer[pixel + 3] = (color) & 0xff;
	}
	else if (fdf->image->endian == 0)
	{
		fdf->image->buffer[pixel + 0] = (color) & 0xff;
		fdf->image->buffer[pixel + 1] = (color >> 8) & 0xff;
		fdf->image->buffer[pixel + 2] = (color >> 16) & 0xff;
		fdf->image->buffer[pixel + 3] = (color >> 24);
	}
}
