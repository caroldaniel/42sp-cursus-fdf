/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:03:59 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/30 15:53:07 by cado-car         ###   ########.fr       */
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
** FDF main data structure
*/
typedef struct s_fdf
{
	t_map	*map;
	void	*mlx;
	int		win_x;
	int		win_y;
	void	*win;
}	t_fdf;

/*-----MACROS---------*/

/*
** Window basic configuration
*/
# define WINDOW_NAME	 	"fdf"
# define WINDOW_WIDTH		800
# define WINDOW_HEIGHT		600

/*
** Conversion bases
*/
# define HEXADECIMAL_L_BASE	"0123456789abcdef"

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

/*
** Initialization utilities
*/
t_point	**init_coordinates(int width, int depth);

#endif