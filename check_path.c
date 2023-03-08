/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:32:28 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/08 15:33:03 by mkerkeni         ###   ########.fr       */
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

void	check_path(t_map *map)
{
	char	**map_test;

	map_test = map->map;
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
	print_map(map_test);
	is_valid_path(map_test);
}
