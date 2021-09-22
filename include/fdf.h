/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:34:00 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/21 23:05:52 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "../include/colors.h"
# include "../include/keys.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>


/*
** Struct to organize data from the '.fdf' file.
** 'int ***coordinates' will be read as maximum of [x][y][2]: 
** --> [x][y][0] for height on the point (x,y) of matrix; 
** --> [x][y][1] for color on the point (x,y) of matrix
*/

typedef struct s_fdf
{
	int	***coordinates;
	int	max_width;
	int max_depth;
	int	max_height;
	int min_height;
}	t_fdf;

/*
** Struct to organize relevant data to the camera.
*/

typedef struct s_cam
{
	int		zoom;
	int		x_pad;
	int		y_pad;
	int		projection;
}	t_cam;

/*
** Struct to organize relevant data of the current line.
*/

typedef struct s_line
{
	float	start_x;
	float	start_y;
	int		start_z;
	int		start_color;
	float	end_x;
	float	end_y;
	int		end_z;
	int		end_color;
}	t_line;

/*
** Struct to organize relevant data to the 'mlx' window:
** --> win_x and win_y are the size of window.
** Includes other struct types in itself.
*/

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
	t_fdf	*fdf;
	t_cam	*cam;
	t_line	*line;
}	t_mlx;

# define WINDOW_NAME		"fdf"

# define SCREEN_WIDTH		1200
# define SCREEN_HEIGHT		800

# define MARGIN				200

# define ISOMETRIC			1

# define COLOR_DEFAULT		C_WHITE
# define HEXADECIMAL_L_BASE	"0123456789abcdef"

# define INITIAL_ZOOM		10

# define ABS(a)		((a < 0) ? -a : a)
# define MAX(a, b)	((a > b) ? a : b)
# define MIN(a, b)	((a < b) ? a : b)
 
// Struct initialization functions
t_fdf	*init_fdf(void);
t_cam	*init_cam(void);
t_mlx	*init_mlx(t_fdf *fdf);
t_line	*init_line(void);

// Utilities initialization functions
int		***init_coordinates(int width, int depth);

// Map parsing functions
t_fdf	*read_fdf_file(char *file_name);

// Error functions
void	error(int exit_code);

// Drawing functions
void 	render(t_mlx *mlx);
void	fill_line(int x1, int y1, int x2, int y2, t_mlx *mlx);
void    draw_line(t_mlx *mlx);

// Key Handle functions
int		key_handle(int keycode, t_mlx *mlx);

// Projection functions
void    isometric(float *x, float *y, int z);


#endif