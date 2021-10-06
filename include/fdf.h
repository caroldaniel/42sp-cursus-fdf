/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:03:59 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/05 22:39:23 by cado-car         ###   ########.fr       */
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
# include "colors.h"

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
	t_point	end;
	float	transform_z;
}	t_line;

/*
** Color struct: valid for line.
*/
typedef struct s_color
{
	int	start_color;
	int	start_r;
	int	start_g;
	int	start_b;
	int	end_color;
	int	end_r;
	int	end_g;
	int	end_b;
	int	delta_r;
	int	delta_g;
	int	delta_b;
}	t_color;

/*
** Image data structure: holds information on the image pointers given by 
** MiniLibX and the buffer pointer from which final image is printed, beside the
** current line to be transfered into the buffer.
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
	int		color_pallet;
	float	scale_factor;
	float	scale_z;
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
# define MAX_PIXEL			1080000

/*
** Colors configuration
*/
# define LINE_DEFAULT		C_WHITE
# define BACKGROUND_DEFAULT	C_GREY
# define C_TEXT				C_WHITE

/*
** Conversion bases & useful angles in rad
*/
# define HEXADECIMAL_L_BASE	"0123456789abcdef"
# define ANG_1				0.01745329
# define ANG_30				0.52359877
# define ANG_45				0.78539816

/*
** Enumerator for projection names and boolean
*/
enum e_projection
{
	ISOMETRIC,
	PERSPECTIVE,
	TOP
};

enum e_bool
{
	FALSE,
	TRUE
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
t_line	*init_line(t_point start, t_point end, t_fdf *fdf);
t_cam	*init_cam(t_map *map);

/*
** Initialization and closing utilities
*/
t_point	**init_coordinates(int width, int depth);
void	center_to_origin(t_map *map);
float	scale_to_fit(t_map *map);
void	reset(t_fdf *fdf);
void	close_all(t_fdf *fdf, int exit_code);
void	close_map(t_fdf *fdf, int exit_code);
t_color	*color_init(t_point start, t_point end);
t_color	*color_pallet_init(int min_color, int max_color);

/*
** Math utilities
*/
float	absolute(float nbr);
float	max(float a, float b);
float	min(float a, float b);

/*
** Drawing functions
*/
void	render(t_fdf *fdf);
void	draw_image(t_image *image, int max_x, int max_y);
void	bresenham(t_fdf *fdf, t_point start, t_point end);
void	pixel_to_image(t_image *image, float x, float y, int color);
void	clear_image(t_image *image, int image_size);
void	print_menu(t_fdf *fdf);
int		get_color(t_color *color, int i_line, int line_size);

/*
** Transformation functions
*/
void	rotate(t_cam *cam, t_line *line);
void	rotate_x(t_line *line, double angle);
void	rotate_y(t_line *line, double angle);
void	rotate_z(t_line *line, double angle);
void	project(t_cam *cam, t_line *line);
void	transform(t_cam *cam, t_line *line);
void	scale(t_line *line, int scale_factor);
void	translate(t_line *line, int move_x, int move_y);

/*
** Key handle functions
*/
int		key_handle(int keycode, t_fdf *fdf);

#endif