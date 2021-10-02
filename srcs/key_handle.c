/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 23:39:42 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/02 13:56:57 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>
int	key_handle(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == NUMPAD_2)
		fdf->cam->alpha += (5 * ANG_1);
	else if (keycode == NUMPAD_8)
		fdf->cam->alpha -= (5 * ANG_1);
	else if (keycode == NUMPAD_4)
		fdf->cam->gamma += (5 * ANG_1);
	else if (keycode == NUMPAD_6)
		fdf->cam->gamma -= (5 * ANG_1);
	else if (keycode == NUMPAD_1)
		fdf->cam->beta += (5 * ANG_1);
	else if (keycode == NUMPAD_3)
		fdf->cam->beta -= (5 * ANG_1);
	else if (keycode == KEY_PLUS)
		fdf->cam->scale_factor += 1;
	else if (keycode == KEY_MINUS)
		fdf->cam->scale_factor -= 1;
	else if (keycode == KEY_RIGHT)
		fdf->cam->move_x += 1;
	else if (keycode == KEY_LEFT)
		fdf->cam->move_x -= 1;
	else if (keycode == KEY_DOWN)
		fdf->cam->move_y += 1;
	else if (keycode == KEY_UP)
		fdf->cam->move_x -= 1;
	else if (keycode == KEY_UP)
		fdf->cam->move_x -= 1;
	else if (keycode == KEY_P)
		fdf->cam->projection = PERSPECTIVE;
	else if (keycode == KEY_I)
		fdf->cam->projection = ISOMETRIC;
	// printf("%i\n", keycode);
	render(fdf);
	return (0);
}
