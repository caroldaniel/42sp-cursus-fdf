/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:29:41 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/30 22:50:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
static int	get_width(char *file_name);
static int	get_depth(char *file_name);
static void	get_points(char *file_name, t_map *map);
static void	fill_point(char *point, t_map *map, int coord_x, int coord_y);

t_map	*read_map(char *file_name)
{
	t_map	*map;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		error(2);
	close(fd);
	map = init_map();
	if (!map)
		error(3);
	map->max_width = get_width(file_name);
	map->max_depth = get_depth(file_name);
	map->coordinates = init_coordinates(map->max_width, map->max_depth);
	if (!map->coordinates)
		error(3);
	get_points(file_name, map);
	return (map);
}

static int	get_width(char *file_name)
{
	int		fd;
	char	*line;
	int		width;
	int		new_width;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	if (!line)
		error(4);
	width = (int)ft_split_count(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		new_width = (int)ft_split_count(line, ' ');
		if (width != new_width)
			error(4);
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

static void	get_points(char *file_name, t_map *map)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;
	int		j;

	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (i < map->max_depth)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		j = 0;
		while (j < map->max_width)
		{
			fill_point(split[j], map, j, i);
			free(split[j]);
			j++;
		}
		free(split);
		free(line);
		i++;
	}
	close(fd);
}

static void	fill_point(char *point, t_map *map, int coord_x, int coord_y)
{
	char	**info;
	int		i;

	map->coordinates[coord_x][coord_y].x = (float)coord_x;
	map->coordinates[coord_x][coord_y].y = (float)coord_y;
	if (ft_strchr(point, ','))
	{
		info = ft_split(point, ',');
		map->coordinates[coord_x][coord_y].z = (float)ft_atoi(info[0]);
		map->coordinates[coord_x][coord_y].color = \
			ft_atoi_base(info[1], HEXADECIMAL_L_BASE);
		i = 0;
		while (info[i])
			free(info[i++]);
		free(info);
	}
	else
	{
		map->coordinates[coord_x][coord_y].z = (float)ft_atoi(point);
		map->coordinates[coord_x][coord_y].color = -1;
	}
	if (map->coordinates[coord_x][coord_y].z > map->max_height)
		map->max_height = map->coordinates[coord_x][coord_y].z;
	if (map->coordinates[coord_x][coord_y].z < map->min_height)
		map->min_height = map->coordinates[coord_x][coord_y].z;
}
