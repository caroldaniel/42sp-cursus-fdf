/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:29:04 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/03 23:04:31 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	print_menu(t_fdf *fdf)
{
	int	y;
	char *projection;

	y = 0;
	if (fdf->cam->projection == ISOMETRIC)
		projection = "Isometric projection";
	else if (fdf->cam->projection == PERSPECTIVE)
		projection = "Perspective projection";
	else if (fdf->cam->projection == TOP)
		projection = "Top view";
	
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 50, TEXT_DEFAULT, projection);
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 35, TEXT_DEFAULT, "Zoom: press '-' or '+'");
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 20, TEXT_DEFAULT, "Move: press arrow keys");
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 20, TEXT_DEFAULT, "Rotate X axis: press '2' or '8'");
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 20, TEXT_DEFAULT, "Rotate Y axis: press '1' or '3'");
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 20, TEXT_DEFAULT, "Rotate Z axis: press '4' or '6'");
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 20, TEXT_DEFAULT, "Scale Altitude: press 'x' or 'z'");
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 35, TEXT_DEFAULT, "To change projection view:");
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 20, TEXT_DEFAULT, "Isometric: press 'I'");
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 20, TEXT_DEFAULT, "Perspective: press 'P'");
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 20, TEXT_DEFAULT, "Top View: press 'O'");
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 35, TEXT_DEFAULT, "Reset view: press 'R'");
}
