/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:04:25 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/22 19:05:29 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

int	key_handle(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_PLUS)
		mlx->cam->zoom += 5;
	else if (keycode == KEY_MINUS)
		mlx->cam->zoom -= 5;
	else if (keycode == KEY_Z)
		mlx->cam->z_scale += 1;
	else if (keycode == KEY_X)
		mlx->cam->z_scale -= 1;
	else if (keycode == KEY_UP)
		mlx->cam->y_shift += 10;
	else if (keycode == KEY_DOWN)
		mlx->cam->y_shift -= 10;
	else if (keycode == KEY_LEFT)
		mlx->cam->x_shift -= 10;
	else if (keycode == KEY_RIGHT)
		mlx->cam->x_shift += 10;
	else if (keycode == NUMPAD_2)
		mlx->cam->alpha += 0.05;
	else if (keycode == NUMPAD_8)
		mlx->cam->alpha -= 0.05;
	else if (keycode == NUMPAD_4)
		mlx->cam->beta -= 0.05;
	else if (keycode == NUMPAD_6)
		mlx->cam->beta += 0.05;
	else if (keycode == NUMPAD_1 || keycode == NUMPAD_3)
		mlx->cam->gamma += 0.05;
	else if (keycode == NUMPAD_7 || keycode == NUMPAD_9)
		mlx->cam->gamma -= 0.05;
	mlx_clear_window(mlx->mlx, mlx->win);
	render(mlx);
	printf("%i\n", keycode);
	return (0);
}
