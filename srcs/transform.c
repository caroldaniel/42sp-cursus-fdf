/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:02:44 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/30 23:03:31 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	scale(t_fdf *fdf)
{
	fdf->line->start.x *= fdf->cam->scale_factor;
	fdf->line->start.y *= fdf->cam->scale_factor;
	fdf->line->start.z *= fdf->cam->scale_factor;
	fdf->line->end.x *= fdf->cam->scale_factor;
	fdf->line->end.y *= fdf->cam->scale_factor;
	fdf->line->end.z *= fdf->cam->scale_factor;
}

void	translate(t_fdf *fdf)
{
	fdf->line->start.x += fdf->cam->center_x + fdf->cam->move_x;
	fdf->line->start.y += fdf->cam->center_y + fdf->cam->move_y;
	fdf->line->end.x += fdf->cam->center_x + fdf->cam->move_x;
	fdf->line->end.y += fdf->cam->center_y + fdf->cam->move_y;
}
