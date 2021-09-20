/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:03:36 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/20 17:53:52 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    bresenham(float x1, float y1, float x2, float y2, t_data *data)
{
    float   x_step;
    float   y_step;
    int     max;

    x_step = x2 - x1;
    y_step = y2 - y1;

    max = MAX(ABS(x_step), ABS(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x1 - x2) || (int)(y1 - y2))
    {
        mlx_pixel_put(data->mlx, data->win, x1, y1, 0xffffff);
        x1 += x_step;
        y1 += y_step;
    }
}
