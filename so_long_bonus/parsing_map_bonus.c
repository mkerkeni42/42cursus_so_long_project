/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:16:48 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/28 10:53:40 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	fill_col_map(t_map *map, char *line)
{
	map->x = 0;
	while (map->x < map->tot_col)
	{
		map->map[map->y][map->x] = line[map->x];
		map->x++;
	}
	map->map[map->y][map->x] = '\0';
}

static void	fill_array_map(t_map *map, char *file_name)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		handle_error(2);
	line = get_next_line(fd);
	len = ft_strlen(line) - 1;
	map->y = 0;
	while (line && map->y < map->tot_row)
	{
		check_rectangle(line, len);
		fill_col_map(map, line);
		free(line);
		line = get_next_line(fd);
		map->y++;
	}
	map->map[map->y] = NULL;
	if (close(fd) == -1)
		handle_error(1);
}

static int	count_rows(char *line, int fd)
{
	int	y;

	y = 0;
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (y);
}

static void	get_size_array(t_map *map, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		handle_error(2);
	line = get_next_line(fd);
	map->tot_col = ft_strlen(line) - 1;
	map->y = count_rows(line, fd);
	map->tot_row = map->y;
	if (close(fd) == -1)
		handle_error(1);
	map->map = malloc(sizeof(char *) * (map->tot_row + 1));
	if (!map->map)
		handle_error(3);
	map->y = 0;
	while (map->y < map->tot_row)
	{
		map->map[map->y] = malloc(sizeof(char) * (map->tot_col + 1));
		if (!map->map[map->y])
			handle_error(3);
		map->y++;
	}
}

t_map	*parse_map(char *file_name)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	get_size_array(map, file_name);
	fill_array_map(map, file_name);
	if (map->map == NULL)
		handle_error(0);
	map->y = 0;
	map->x = 0;
	check_map_closed(map);
	check_collectible(map);
	check_element(map);
	check_path(map);
	return (map);
}
