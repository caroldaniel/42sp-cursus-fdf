/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:08:35 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/04 00:13:59 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
static void	close_coordinates(t_point **coordinates, int width);

void	close_all(t_fdf *fdf, int exit_code)
{
	if (fdf)
	{
		if (fdf->map)
		{
			if (fdf->map->coordinates)
				close_coordinates(fdf->map->coordinates, fdf->map->max_x);
			free(fdf->map);
		}
		if (fdf->image)
		{
			if (fdf->image->image)
				mlx_destroy_image(fdf->mlx, fdf->image->image);
			if (fdf->image->line)
				free (fdf->image->line);
			free(fdf->image);
		}
		if (fdf->cam)
			free (fdf->cam);
		if (fdf->win)
			mlx_destroy_window(fdf->mlx, fdf->win);
		if (fdf->mlx)
			mlx_destroy_display(fdf->mlx);
		free(fdf);
	}
	error(exit_code);
}

void	close_map(t_fdf *fdf, int exit_code)
{
	close_coordinates(fdf->map->coordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf);
	error(exit_code);
}

static void	close_coordinates(t_point **coordinates, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		free(coordinates[i]);
		i++;
	}
	free(coordinates);
}
