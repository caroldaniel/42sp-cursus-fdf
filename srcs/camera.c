/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 23:23:36 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/22 13:31:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	zoom(t_mlx *mlx)
{
	mlx->line->start_x *= mlx->cam->zoom;
	mlx->line->start_y *= mlx->cam->zoom;
	mlx->line->end_x *= mlx->cam->zoom;
	mlx->line->end_y *= mlx->cam->zoom;
}

void	shift(t_mlx *mlx)
{
	mlx->line->start_x += mlx->cam->x_shift;
	mlx->line->start_y -= mlx->cam->y_shift;
	mlx->line->end_x += mlx->cam->x_shift;
	mlx->line->end_y -= mlx->cam->y_shift;
}

void	scale_z(t_mlx *mlx)
{
	mlx->line->start_z *= mlx->cam->z_scale;
	mlx->line->end_z *= mlx->cam->z_scale;
}

void	rotate(t_mlx *mlx)
{
	double	alpha;
	double	beta;
	double	gamma;

	alpha = mlx->cam->alpha;
	beta = mlx->cam->beta;
	gamma = mlx->cam->gamma;
	
	mlx->line->start_y = mlx->line->start_y * cos(alpha) + mlx->line->start_z * sin(alpha);
	mlx->line->start_z = -mlx->line->start_y * sin(alpha) + mlx->line->start_z * cos(alpha);	
	mlx->line->end_y = mlx->line->end_y * cos(alpha) + mlx->line->end_z * sin(alpha);
	mlx->line->end_z = -mlx->line->end_y * sin(alpha) + mlx->line->end_z * cos(alpha);	

	mlx->line->start_x = mlx->line->start_x * cos(beta) + mlx->line->start_z * sin(beta);
	mlx->line->start_z = -mlx->line->start_x * sin(beta) + mlx->line->start_z * cos(beta);	
	mlx->line->end_x = mlx->line->end_x * cos(beta) + mlx->line->end_z * sin(beta);
	mlx->line->end_z = -mlx->line->end_x * sin(beta) + mlx->line->end_z * cos(beta);	

	mlx->line->start_x = mlx->line->start_x * cos(gamma) - mlx->line->start_y * sin(gamma);
	mlx->line->start_y = mlx->line->start_x * sin(gamma) + mlx->line->start_y * cos(gamma);
	mlx->line->end_x = mlx->line->end_x * cos(gamma) - mlx->line->end_y * sin(gamma);
	mlx->line->end_y = mlx->line->end_x * sin(gamma) + mlx->line->end_y * cos(gamma);
}
