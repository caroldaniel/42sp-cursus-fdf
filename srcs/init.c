/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:36:24 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/30 23:09:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		error(3);
	fdf->map = read_map(file_name);
	fdf->mlx = mlx_init();
	fdf->win_x = WINDOW_WIDTH;
	fdf->win_y = WINDOW_HEIGHT;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, WINDOW_NAME);
	fdf->image = init_image(fdf->mlx);
	if (!fdf->image)
		error(5);
	fdf->line = NULL;
	fdf->cam = init_cam();
	if (!fdf->cam)
		error(6);
	fdf->cam->scale_factor = scale_to_fit(fdf->map);
	return (fdf);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->coordinates = NULL;
	map->max_width = 0;
	map->max_depth = 0;
	map->max_height = 0;
	map->min_height = 0;
	return (map);
}

t_image	*init_image(void *mlx)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	image->buffer = mlx_get_data_addr(image->image, &image->pixel_bits, \
			&image->line_bytes, &image->endian);
	return (image);
}

t_line	*init_line(t_point start, t_point end)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start = start;
	line->end = end;
	return (line);
}

t_cam	*init_cam(void)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->projection = ISOMETRIC;
	cam->scale_factor = 0;
	cam->move_x = 0;
	cam->move_y = 0;
	cam->center_x = WINDOW_WIDTH / 2;
	cam->center_y = WINDOW_HEIGHT / 2;
	return (cam);
}
