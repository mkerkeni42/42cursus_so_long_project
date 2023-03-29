/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:19:37 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/28 11:15:57 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(char *line, size_t len)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
	if (ft_strlen(line) != len)
		handle_error(4);
}

void	check_map_closed(t_map *map)
{
	map->y = 0;
	while (map->y < map->tot_row)
	{
		map->x = 0;
		while (map->x < map->tot_col)
		{
			if ((map->y == 0 || map->y == map->tot_row - 1)
				&& map->map[map->y][map->x] != '1')
				handle_error(5);
			else if (map->y != 0 && map->y != map->tot_row - 1
				&& (map->x == 0 || map->x == map->tot_col - 1))
			{
				if (map->map[map->y][map->x] != '1')
					handle_error(5);
			}
			map->x++;
		}
		map->y++;
	}
}

void	check_collectible(t_map *map)
{
	map->y = 0;
	while (map->y < map->tot_row)
	{
		if (!ft_strchr(map->map[map->y], 'C'))
			map->y++;
		else
			break ;
	}
	if (map->y == map->tot_row)
		handle_error(6);
}

void	check_element(t_map *map)
{
	int	count_p;
	int	count_e;

	count_p = 0;
	count_e = 0;
	map->y = -1;
	while (++map->y < map->tot_row)
	{
		map->x = -1;
		while (++map->x < map->tot_col)
		{
			if (map->map[map->y][map->x] == 'P')
				count_p++;
			else if (map->map[map->y][map->x] == 'E')
				count_e++;
			else if (map->map[map->y][map->x] != '0'
				&& map->map[map->y][map->x] != '1'
				&& map->map[map->y][map->x] != 'C')
				handle_error(8);
		}
	}
	if (count_p != 1 || count_e != 1)
		handle_error(7);
}
