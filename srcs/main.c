/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:33:55 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/18 15:32:21 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char 	*file_name;
	t_fdf	*fdf;
	// t_mlx	*mlx;
	
	if (argc != 2)
		error(1);
	file_name = argv[1];
	fdf = init_fdf();
	if (!read_fdf_file(file_name, fdf))
		error(2);
		
	// int i = 0;
	// while (i < fdf->max_depth)
	// {
	// 	int j = 0;
	// 	while (j < fdf->max_width)
	// 	{
	// 		printf("x: %2i, y: %2i, z: %3i, color: ", j, i, fdf->coordinates[j][i][0]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
}