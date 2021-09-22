/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:04:25 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/21 20:02:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

int key_handle(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_I)
		mlx->cam->zoom += 1;
	else if (keycode == KEY_O) 
    {
        if (mlx->cam->zoom > 1)
		    mlx->cam->zoom -= 1;
    }
	else if (keycode == KEY_ESC) 
		exit(0);
	return (0);
}
