/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:17:20 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/22 19:03:47 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	project_line(int x1, int y1, int x2, int y2, t_mlx *mlx)
{
	mlx->line->start_x = x1;
	mlx->line->start_y = y1;
	mlx->line->end_x = x2;
	mlx->line->end_y = y2;
	zoom(mlx);
	mlx->line->start_z = mlx->fdf->coordinates[x1][y1][0];
	mlx->line->end_z = mlx->fdf->coordinates[x2][y2][0];
	if (mlx->fdf->coordinates[x1][y1][1] >= 0)
		mlx->line->start_color = mlx->fdf->coordinates[x1][y1][1];
	if (mlx->fdf->coordinates[x2][y2][1] >= 0)
		mlx->line->end_color = mlx->fdf->coordinates[x2][y2][1];
	scale_z(mlx);
	rotate(mlx);
	if (mlx->cam->projection == ISOMETRIC)
	{
		isometric(&mlx->line->start_x, &mlx->line->start_y, mlx->line->start_z);
		isometric(&mlx->line->end_x, &mlx->line->end_y, mlx->line->end_z);
	}
	shift(mlx);
}


void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(M_PI / 3);
    *y = (*x + *y) * sin(M_PI / 6) - z;
}
