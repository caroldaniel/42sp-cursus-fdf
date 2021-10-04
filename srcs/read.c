/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:29:41 by cado-car          #+#    #+#             */
/*   Updated: 2021/10/04 00:19:34 by cado-car         ###   ########.fr       */
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
		return (NULL);
	map->max_x = get_width(file_name);
	if (!map->max_x)
	{
		free(map);
		return (NULL);		
	}
	map->max_y = get_depth(file_name);
	map->coordinates = init_coordinates(map->max_x, map->max_y);
	if (!map->coordinates)
	{
		free(map);
		return (NULL);
	}
	get_points(file_name, map);
	center_to_origin(map);
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
		return (0);
	width = (int)ft_split_count(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		new_width = (int)ft_split_count(line, ' ');
		if (width != new_width)
			return (0);
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
	int		x;
	int		y;

	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	while (y < map->max_y)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		x = 0;
		while (x < map->max_x)
		{
			fill_point(split[x], map, x, y);
			free(split[x]);
			x++;
		}
		free(split);
		free(line);
		y++;
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
		map->coordinates[coord_x][coord_y].color = LINE_DEFAULT;
	}
	if (map->coordinates[coord_x][coord_y].z > map->max_z)
		map->max_z = map->coordinates[coord_x][coord_y].z;
	if (map->coordinates[coord_x][coord_y].z < map->min_z)
		map->min_z = map->coordinates[coord_x][coord_y].z;
}