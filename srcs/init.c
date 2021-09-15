/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:49:11 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/14 23:10:47 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf	*init_fdf(void)
{
	t_fdf *fdf;
	
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->coordinates[2] = NULL;
	fdf->max_width = 0;
	fdf->max_depth = 0;
	fdf->max_height = 0;
	fdf->min_height = 0;
	return (fdf);
}