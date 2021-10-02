/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 23:39:42 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/02 00:03:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_handle(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		exit(0);
	render(fdf);
	return (0);
}
