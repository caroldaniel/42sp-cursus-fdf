/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:57:15 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/21 22:49:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	***init_coordinates(int width, int depth)
{
	int	i;
	int	j;
	int	***coordinates;

	coordinates = (int ***)malloc(width * sizeof(int **));
	if (!coordinates)
		return (NULL);
	i = 0;
	while (i < width)
	{
		coordinates[i] = (int **)malloc(depth * sizeof(int *));
		if (!coordinates[i])
			return (NULL);
		j = 0;
		while (j < depth)
		{
			coordinates[i][j] = (int *)malloc(2 * sizeof(int));
			if (!coordinates[i][j])
				return (NULL);
			j++;
		}
		i++;
	}
	return (coordinates);
}

void	fill_line(int x1, int y1, int x2, int y2, t_mlx *mlx)
{
	mlx->line->start_x = (float)(x1 * mlx->cam->zoom) + mlx->cam->x_pad;
	mlx->line->start_y = (float)(y1 * mlx->cam->zoom) - mlx->cam->y_pad;
	mlx->line->start_z = mlx->fdf->coordinates[x1][y1][0];
	if (mlx->fdf->coordinates[x1][y1][1] >= 0)
		mlx->line->start_color = mlx->fdf->coordinates[x1][y1][1];
	mlx->line->end_x = (float)(x2 * mlx->cam->zoom) + mlx->cam->x_pad;
	mlx->line->end_y = (float)(y2 * mlx->cam->zoom) - mlx->cam->y_pad;
	mlx->line->end_z = mlx->fdf->coordinates[x2][y2][0];
	if (mlx->fdf->coordinates[x2][y2][1] >= 0)
		mlx->line->end_color = mlx->fdf->coordinates[x2][y2][1];
	if (mlx->cam->projection == ISOMETRIC)
	{
		isometric(&mlx->line->start_x, &mlx->line->start_y, mlx->line->start_z);
		isometric(&mlx->line->end_x, &mlx->line->end_y, mlx->line->end_z);
	}
}
