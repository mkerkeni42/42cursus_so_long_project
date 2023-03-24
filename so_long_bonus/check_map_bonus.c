/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:19:37 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/24 10:34:07 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	check_start(t_map *map)
{
	int	count;

	count = 0;
	map->y = 0;
	while (map->y < map->tot_row)
	{
		count += count_char(map->map[map->y], 'P');
		map->y++;
	}
	if (count == 0 || count > 1)
		handle_error(7);
}

void	check_exit(t_map *map)
{
	int	count;

	count = 0;
	map->y = 0;
	while (map->y < map->tot_row)
	{
		count += count_char(map->map[map->y], 'E');
		map->y++;
	}
	if (count == 0 || count > 1)
		handle_error(8);
}
