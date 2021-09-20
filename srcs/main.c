/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:33:55 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/20 17:54:48 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	char	*file_name;
	t_fdf	*fdf;
	t_data	*data;

	if (argc != 2)
		error(1);
	file_name = argv[1];
	fdf = init_fdf();
	if (!read_fdf_file(file_name, fdf))
		error(2);
	data = init_data();
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 600, 600, "fdf");
	bresenham(10, 10, 300, 300, data);
	mlx_loop(data->mlx);
}
