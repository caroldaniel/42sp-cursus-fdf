/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:03:36 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/21 23:00:28 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    draw_line(t_mlx *mlx)
{
    float   x_step;
    float   y_step;
    int     max;
    int     color;

    color = C_WHITE;
    // if (mlx->line->start_z)
    //     color = C_RED;
    x_step = mlx->line->end_x - mlx->line->start_x;
    y_step = mlx->line->end_y - mlx->line->start_y;
    max = MAX(ABS(x_step), ABS(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(mlx->line->start_x - mlx->line->end_x) \
		|| (int)(mlx->line->start_y - mlx->line->end_y))
    {
        if (mlx->line->start_x > 0 && mlx->line->start_y > 0)
			mlx_pixel_put(mlx->mlx, mlx->win, mlx->line->start_x, \
				mlx->line->start_y, color);
        mlx->line->start_x += x_step;
        mlx->line->start_y += y_step;
    }
}

void render(t_mlx *mlx)
{
    int     x;
    int     y;

    y = 0; 
    while (y < mlx->fdf->max_depth)
    {
		x = 0;
		while (x < mlx->fdf->max_width)
		{
			if (x < mlx->fdf->max_width - 1)
			{
				fill_line(x, y, x + 1, y, mlx);
				draw_line(mlx);
			}
            if (y < mlx->fdf->max_depth - 1)
			{
				fill_line(x, y, x, y + 1, mlx);
				draw_line(mlx);
			}
			x++;
        }
        y++;
    }
}

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(M_PI / 4);
    *y = (*x + *y) * sin(M_PI / 4) - z;
}
