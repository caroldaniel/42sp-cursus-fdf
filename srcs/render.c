/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:40:08 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/02 00:13:16 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>
void	render(t_fdf *fdf)
{
	// int	x;
	// int	y;

	// y = 0;
	// while (y < fdf->map->max_y)
	// {
	// 	x = 0;
	// 	while (x < fdf->map->max_x)
	// 	{
	// 		printf("%2.f, %2.f, %2.f	", fdf->map->coordinates[x][y].x, fdf->map->coordinates[x][y].y, fdf->map->coordinates[x][y].z);
	// 		x++;
	// 	}
	// 	printf("\n");
	// 	y++;
	// }
	
	transfer_coordinates(fdf);
	clear_image(fdf->image, fdf->map->max_x, fdf->map->max_y);

	

	
	// rotate(fdf, fdf->map->max_x, fdf->map->max_y);	
	// project(fdf, fdf->map->max_x, fdf->map->max_y);
	// transform(fdf, fdf->map->max_x, fdf->map->max_y);
	draw_image(fdf->image, fdf->map->max_x, fdf->map->max_y);
}



