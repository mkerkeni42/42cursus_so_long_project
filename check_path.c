/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:32:28 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/22 15:10:32 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_valid_path(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				handle_error(11);
			x++;
		}
		y++;
	}
}

static void	check_around_position(char	**map, int x, int y)
{
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'X')
		map[y][x + 1] = '|';
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'X')
		map[y][x - 1] = '|';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'X')
		map[y + 1][x] = '|';
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'X')
		map[y - 1][x] = '|';
}

static char	**fill_cpy_map(t_map *map, char **map_cpy)
{
	map->y = 0;
	map->x = 0;
	while (map->map[map->y])
	{
		map->x = 0;
		while (map->map[map->y][map->x])
		{
			map_cpy[map->y][map->x] = map->map[map->y][map->x];
			map->x++;
		}
		map_cpy[map->y][map->x] = '\0';
		map->y++;
	}
	map_cpy[map->y] = NULL;
	return (map_cpy);
}

static char	**get_cpy_map(t_map *map)
{
	char	**map_cpy;

	map_cpy = malloc(sizeof(char *) * (map->tot_row + 1));
	if (!map_cpy)
		handle_error(3);
	map->y = 0;
	while (map->y < map->tot_row)
	{
		map_cpy[map->y] = malloc(sizeof(char) * (map->tot_col + 1));
		if (!map_cpy[map->y])
			handle_error(3);
		map->y++;
	}
	map_cpy = fill_cpy_map(map, map_cpy);
	return (map_cpy);
}

void	check_path(t_map *map)
{
	char	**map_test;

	map_test = get_cpy_map(map);
	map->x = 0;
	map->y = 0;
	while (map_test[map->y])
	{
		map->x = 0;
		while (map_test[map->y][map->x])
		{
			if (map_test[map->y][map->x] == 'P'
				|| map_test[map->y][map->x] == '|')
			{
				map_test[map->y][map->x] = 'X';
				check_around_position(map_test, map->x, map->y);
				map->y = 0;
				break ;
			}
			map->x++;
		}
		map->y++;
	}
	is_valid_path(map_test);
	free_map(map_test);
}
