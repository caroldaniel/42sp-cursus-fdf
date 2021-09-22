/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:49:11 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/22 19:04:47 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->coordinates = NULL;
	fdf->max_width = 0;
	fdf->max_depth = 0;
	fdf->max_height = 0;
	fdf->min_height = 0;
	return (fdf);
}

t_cam	*init_cam(void)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->zoom = INITIAL_ZOOM;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->z_scale = INITIAL_ZOOM;
	cam->projection = ISOMETRIC;
	cam->x_shift = MARGIN;
	cam->y_shift = -MARGIN;
	return (cam);
}

t_mlx	*init_mlx(t_fdf *fdf)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->win_x = SCREEN_WIDTH;
	mlx->win_y = SCREEN_HEIGHT;
	mlx->fdf = fdf;
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_x, mlx->win_y, WINDOW_NAME);
	mlx->cam = init_cam();
	mlx->line = init_line();
	return (mlx);
}

t_line	*init_line(void)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start_x = 0;
	line->start_y = 0;
	line->start_z = 0;
	line->start_color = COLOR_DEFAULT;
	line->end_x = 0;
	line->end_y = 0;
	line->end_z = 0;
	line->end_color = COLOR_DEFAULT;
	return (line);
}
