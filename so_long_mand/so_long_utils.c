/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:07:39 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/23 11:15:33 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_error(int x)
{
	if (x == 0)
		write(2, "Failed to get the map\n", 22);
	else if (x == 1)
		write(2, "Failed to close the file\n", 25);
	else if (x == 2)
		write(2, "Failed to open the file\n", 24);
	else if (x == 3)
		write(2, "Malloc error\n", 13);
	else if (x == 4)
		write(2, "Your map is not rectangular !\n", 30);
	else if (x == 5)
		write(2, "Your map is not surrounded by walls !\n", 38);
	else if (x == 6)
		write(2, "There is no collectible in your map !\n", 38);
	else if (x == 7)
		write(2, "You map hasn't one start position !\n", 36);
	else if (x == 8)
		write(2, "You map hasn't one exit !\n", 26);
	else if (x == 9)
		write(2, "Wrong number of arguments !\n", 28);
	else if (x == 10)
		write(2, "Your argument has a wrong extension !\n", 38);
	else if (x == 11)
		write(2, "Your path is not practicable !\n", 31);
	exit(EXIT_FAILURE);
}

int	ft_exit_game(t_game *game, int x)
{
	if (x == 1)
		write(2, "The path of your image is wrong !\n", 35);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

int	count_char(char	*str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		exit(EXIT_FAILURE);
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	print_map(char **map)
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
			write(1, &map[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}
