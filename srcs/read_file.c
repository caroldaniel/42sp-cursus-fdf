/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:43:12 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/20 14:29:31 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
static int	get_depth(char *file_name);
static int	get_width(char *file_name);
static void	get_points(char *file_name, t_fdf *fdf);
static void	get_height_color(char *point, t_fdf *fdf, int coord_x, int coord_y);

int	read_fdf_file(char *file_name, t_fdf *fdf)
{
	if (!file_name || !fdf)
		return (0);
	fdf->max_width = get_width(file_name);
	fdf->max_depth = get_depth(file_name);
	fdf->coordinates = init_coordinates(fdf->max_width, fdf->max_depth);
	get_points(file_name, fdf);
	return (1);
}

static int	get_width(char *file_name)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	width = (int)ft_split_count(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
	close(fd);
	return (width);
}

static int	get_depth(char *file_name)
{
	int		fd;
	int		depth;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	depth = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_isprint(*line))
			depth++;
		free(line);
	}
	close(fd);
	return (depth);
}

static void	get_points(char *file_name, t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;
	int		j;

	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (i < fdf->max_depth)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		j = 0;
		while (j < fdf->max_width)
		{
			get_height_color(split[j], fdf, j, i);
			free(split[j]);
			j++;
		}
		free(split);
		free(line);
		i++;
	}
	close(fd);
}

static void	get_height_color(char *point, t_fdf *fdf, int coord_x, int coord_y)
{
	char	**info;
	int		i;

	if (ft_strchr(point, ','))
	{
		info = ft_split(point, ',');
		fdf->coordinates[coord_x][coord_y][0] = ft_atoi(info[0]);
		fdf->coordinates[coord_x][coord_y][1] = \
			ft_atoi_base(info[1], HEXADECIMAL_L_BASE);
		i = 0;
		while (info[i])
			free(info[i++]);
		free(info);
	}
	else
	{
		fdf->coordinates[coord_x][coord_y][0] = ft_atoi(point);
		fdf->coordinates[coord_x][coord_y][1] = \
			ft_atoi_base(COLOR_DEFAULT, HEXADECIMAL_L_BASE);
	}
	if (fdf->coordinates[coord_x][coord_y][0] > fdf->max_height)
		fdf->max_height = fdf->coordinates[coord_x][coord_y][0];
	if (fdf->coordinates[coord_x][coord_y][0] < fdf->min_height)
		fdf->min_height = fdf->coordinates[coord_x][coord_y][0];
}
