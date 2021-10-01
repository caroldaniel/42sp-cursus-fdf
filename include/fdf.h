/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:03:59 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/30 22:33:38 by cado-car         ###   ########.fr       */
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
	int		max_width;
	int		max_depth;
	int		max_height;
	int		min_height;
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
}	t_image;

/*
** line data structure
*/
typedef struct s_line
{
	t_point	start;
	t_point	end;
}	t_line;

/*
** Camera data structure
*/
typedef struct s_cam
{
	int		scale_factor;
	int		move_x;
	int		move_y;
	float	center_x;
	float	center_y;
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
	t_line	*line;
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
# define SCALE				20

/*
** Conversion bases
*/
# define HEXADECIMAL_L_BASE	"0123456789abcdef"

/*
** Math
*/
# define ABS(a)		((a < 0) ? -a : a)
# define MAX(a, b)	((a > b) ? a : b)
# define MIN(a, b)	((a < b) ? a : b)

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
t_point	init_point(void);
t_image	*init_image(void *mlx);
t_line	*init_line(t_point start, t_point end);
t_cam	*init_cam(void);

/*
** Initialization utilities
*/
t_point	**init_coordinates(int width, int depth);
float	scale_to_fit(t_map *map);

/*
** Drawing functions
*/
void	render(t_fdf *fdf);
void	project_line(t_fdf *fdf);
void    draw_line(t_fdf *fdf, t_point start, t_point end);
void	pixel_to_image(t_fdf *fdf, float x, float y, int color);

/*
** Projection math functions
*/
void	coordinates_to_origin(t_map *map);
void	scale(t_fdf *fdf);
void	translate(t_fdf *fdf);

#endif