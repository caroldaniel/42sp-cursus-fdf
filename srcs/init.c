/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:36:24 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/30 15:53:32 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->map = read_map(file_name);
	fdf->mlx = mlx_init();
	fdf->win_x = WINDOW_WIDTH;
	fdf->win_y = WINDOW_HEIGHT;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, WINDOW_NAME);
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

t_point	init_point(void)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	point.z = 0;
	point.color = 0;
	return (point);
}
