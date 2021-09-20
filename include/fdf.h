/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:00 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/20 14:33:40 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_fdf
{
	int	***coordinates;
	int	max_width;
	int max_depth;
	int	max_height;
	int min_height;
}	t_fdf;

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

# define COLOR_DEFAULT		"0x000000"
# define HEXADECIMAL_L_BASE	"0123456789abcdef"

# define ABS(a)		((a < 0) ? -a : a)
# define MAX(a, b)	((a > b) ? a : b)
# define MIN(a, b)	((a < b) ? a : b)
 
// Initialization functions
t_fdf	*init_fdf(void);
int		***init_coordinates(int width, int depth);
t_data	*init_data(void);

// Map parsing functions
int		read_fdf_file(char *file_name, t_fdf *fdf);

// Error functions
void	error(int exit_code);

// Drawing functions
void    bresenham(float x1, float y1, float x2, float y2, t_data *data);

#endif