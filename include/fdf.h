/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:00 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/18 15:50:16 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// # include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// typedef struct s_mlx
// {
// 	void	*mlx;	
// 	void	*win;
// }	t_mlx;

typedef struct s_fdf
{
	int	***coordinates;
	int	max_width;
	int max_depth;
	int	max_height;
	int min_height;
}	t_fdf;

# define COLOR_DEFAULT		"0x000000"
# define HEXADECIMAL_L_BASE	"0123456789abcdef"

// Initialization functions
t_fdf	*init_fdf(void);
int		***init_coordinates(int width, int depth);

// Map parsing functions
int		read_fdf_file(char *file_name, t_fdf *fdf);

// Error functions
void	error(int exit_code);

#endif