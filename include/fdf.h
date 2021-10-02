/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:03:59 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/02 00:13:43 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*------LIBRARIES------*/

/*
** Basic libraries for the previous allowed functions: open, read, write, close,
** malloc, free, perror, strerror and exit. 
*/
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*
** Allowed libraries: math and minilibx, witch is appended in the project's 
** folder to guarantee usage by testers. 
*/
# include <math.h>
# include "../mlx_linux/mlx.h"

/*
** My own libft library, completed with previously implemented functions such as
** get_next_line and ft_printf. 
*/
# include "../libft/libft.h"

/*
** Other fdf libraries
*/
# include "keys.h"

/*------STRUCTS-------*/

/*
** Single point definition
*/
typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

/*
** Map definition
*/
typedef struct s_map
{
	t_point	**coordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}	t_map;

/*
** Image data structure
*/
typedef struct s_image
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	t_point	**coordinates;
	int		max_u;
	int		max_v;
}	t_image;

/*
** Camera data structure
*/
typedef struct s_cam
{
	int		projection;
	int		scale_factor;
	int		move_x;
	int		move_y;
	double	alpha;
	double	beta;
	double	gamma;
}	t_cam;

/*
** FDF main data structure
*/
typedef struct s_fdf
{
	t_map	*map;
	void	*mlx;
	int		win_x;
	int		win_y;
	void	*win;
	t_image	*image;
	t_cam	*cam;
}	t_fdf;

/*-----MACROS---------*/

/*
** Window basic configuration
*/
# define WINDOW_NAME	 	"fdf"
# define WINDOW_WIDTH		800
# define WINDOW_HEIGHT		600
# define MAX_PIXEL			WINDOW_WIDTH * WINDOW_HEIGHT

/*
** Conversion bases & angles in rad
*/
# define HEXADECIMAL_L_BASE	"0123456789abcdef"
# define ANG_1				M_PI / 180
# define ANG_30				M_PI / 6 

/*
** Math
*/
# define ABS(a)		((a < 0) ? -a : a)
# define MAX(a, b)	((a > b) ? a : b)
# define MIN(a, b)	((a < b) ? a : b)


enum e_projection
{
	ISOMETRIC,
	PERSPECTIVE
};

/*-----FUNCTIONS------*/

/*
** Read and parse maps
*/
t_map	*read_map(char *file_name);

/*
** Error management
*/
void	error(int exit_code);

/*
** Structs initialization
*/
t_fdf	*init_fdf(char *file_name);
t_map	*init_map(void);
t_image	*init_image(void *mlx, t_map *map);
t_cam	*init_cam(t_map *map);

/*
** Initialization utilities
*/
t_point	**init_coordinates(int width, int depth);
void	center_to_origin(t_map *map);
float	scale_to_fit(t_map *map);
void	transfer_coordinates(t_fdf *fdf);

/*
** Drawing functions
*/
void	render(t_fdf *fdf);
void	draw_image(t_image *image, int max_x, int max_y);
void	bresenham(t_image *image, t_point start, t_point end);
void	pixel_to_image(t_image *image, float x, float y, int color);
void	clear_image(t_image *image, int max_x, int max_y);

/*
** Transformation functions
*/
void	transform(t_fdf *fdf, int max_x, int max_y);
void	rotate(t_fdf *fdf, int max_x, int max_y);
void	project(t_fdf *fdf, int max_x, int max_y);

/*
** Key handle functions
*/
int		key_handle(int keycode, t_fdf *fdf);

#endif