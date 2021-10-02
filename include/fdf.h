/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:03:59 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/02 14:55:24 by cado-car         ###   ########.fr       */
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
** Single point struct: x, y, z and color values for each point in map.
*/
typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

/*
** Map data struct: holds information on the map parsed, such as a matrix with 
** its point in coordinates, total width, depth and height values passed. 
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
** Current line being printed
*/
typedef struct s_line
{
	t_point	start;
	t_point end;
}	t_line;

/*
** Image data structure: holds information on the image pointers given by MiniLibX
** and the buffer pointer from which final image is printed, beside the current
** line to be transfered into the buffer.
*/
typedef struct s_image
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	t_line	*line;
}	t_image;

/*
** Camera data structure: holds information about the displayed image, such as 
** type of projection, scale, translation delta and angle values for rotation on
** three axes.
*/
typedef struct s_cam
{
	int		projection;
	float	scale_factor;
	float	move_x;
	float	move_y;
	double	alpha;
	double	beta;
	double	gamma;
}	t_cam;

/*
** FDF main data structure: holds all the information necessary for the fdf to
** run, so its made easier to be passed by reference by sub-functions.
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
# define WINDOW_WIDTH		1200
# define WINDOW_HEIGHT		900
# define MAX_PIXEL			WINDOW_WIDTH * WINDOW_HEIGHT

/*
** Conversion bases & useful angles in rad
*/
# define HEXADECIMAL_L_BASE	"0123456789abcdef"
# define ANG_1				M_PI / 180
# define ANG_30				M_PI / 6 
# define ANG_45				M_PI / 4 
# define ANG_60				M_PI / 3 

/*
** Math macros
*/
# define ABS(a)		((a < 0) ? -a : a)
# define MAX(a, b)	((a > b) ? a : b)
# define MIN(a, b)	((a < b) ? a : b)

/*
** Enumerator for projection names
*/
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
t_image	*init_image(void *mlx);
t_line	*init_line(t_point start, t_point end);
t_cam	*init_cam(t_map *map);

/*
** Initialization utilities
*/
t_point	**init_coordinates(int width, int depth);
void	center_to_origin(t_map *map);
float	scale_to_fit(t_map *map);

/*
** Drawing functions
*/
void	render(t_fdf *fdf);
void	draw_image(t_image *image, int max_x, int max_y);
void	bresenham(t_fdf *fdf, t_point start, t_point end);
void	pixel_to_image(t_image *image, float x, float y, int color);
void	clear_image(t_image *image, int image_size);

/*
** Transformation functions
*/
void	rotate(t_cam *cam, t_line *line);
void	project(t_cam *cam, t_line *line);
void	transform(t_cam *cam, t_line *line);

/*
** Key handle functions
*/
int		key_handle(int keycode, t_fdf *fdf);

#endif