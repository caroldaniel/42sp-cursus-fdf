/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:29:04 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/03 22:46:15 by cado-car         ###   ########.fr       */
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
	mlx_string_put(fdf->mlx, fdf->win, 50, y += 20, TEXT_DEFAULT, "Move: press ");
}
