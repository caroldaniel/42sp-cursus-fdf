/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:33:55 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/22 08:41:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	char	*file_name;
	t_fdf	*fdf;
	t_mlx	*mlx;

	if (argc != 2)
		error(1);
	file_name = argv[1];
	fdf = read_fdf_file(file_name);
	mlx = init_mlx(fdf);
	render(mlx);
	mlx_key_hook(mlx->win, &key_handle, mlx);
	mlx_loop(mlx->mlx);
}
