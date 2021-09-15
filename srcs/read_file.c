/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:43:12 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/14 23:16:29 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
static int	get_depth(char *file_name);
static int	get_width(char *file_name);
static void	get_points(char *file_name, t_fdf *fdf);
static void	get_height_color(char *point, t_fdf *fdf, int *height, int *color);

int	read_fdf_file(char *file_name, t_fdf *fdf)
{
	if (!file_name || !fdf)
		return (0);
	*fdf->max_width = get_width(file_name);
	*fdf->max_depth = get_depth(file_name);
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
	close(fd);
	return (width);
}

static int	get_depth(char *file_name)
{
	int fd;
	int depth;

	fd = open(file_name, O_RDONLY, 0);
	depth = 0;
	while(get_next_line(fd))
		depth++;
	close(fd);
	return (depth);
}

static void	get_points(char *file_name, t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;
	int 	j;

	fd = open(file_name, O_RDONLY, 0);
	j = 0;
	while (i < *fdf->max_depth)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		i = 0;
		while (j < (int)ft_split_count(line, ' '))
		{
			get_height_color(split[j], fdf, &fdf->coordinates[i][j][0], &fdf->coordinates[i][j][0]);
			free(split[j]);
			j++;
		}
		free(split);
		free(line);
		i++;
	}
	close(fd);
}

static void	get_height_color(char *point, t_fdf *fdf, int *height, int *color)
{
	char	**info;
	if (ft_strchr(point, ','))
	{
		info = ft_split(point, ',');
		*height = ft_atoi(info[0]);
		*color = ft_atoi_base(info[1], HEXADECIMAL_L_BASE);
		free(info);
	}
	else
	{
		*height = ft_atoi(point);
		*color = ft_atoi_base(COLOR_DEFAULT, HEXADECIMAL_L_BASE);
	}
	if (*height > *fdf->max_height)
		*fdf->max_height = *height;
	if (*height < *fdf->min_height)
		*fdf->min_height = *height;
}