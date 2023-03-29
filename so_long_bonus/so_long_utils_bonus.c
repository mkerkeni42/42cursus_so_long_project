/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:07:39 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/29 10:56:46 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	handle_error(int x)
{
	if (x == 0)
		write(2, "Error\nFailed to get the map\n", 28);
	else if (x == 1)
		write(2, "Error\nFailed to close the file\n", 31);
	else if (x == 2)
		write(2, "Error\nFailed to open the file\n", 30);
	else if (x == 3)
		write(2, "Error\nMalloc error\n", 19);
	else if (x == 4)
		write(2, "Error\nYour map is not rectangular !\n", 36);
	else if (x == 5)
		write(2, "Error\nYour map is not surrounded by walls !\n", 44);
	else if (x == 6)
		write(2, "Error\nThere is no collectible in your map !\n", 44);
	else if (x == 7)
		write(2, "Error\nWrong number of start or exit position !\n", 47);
	else if (x == 8)
		write(2, "Error\nYour map has wrong elements !\n", 36);
	else if (x == 9)
		write(2, "Error\nWrong number of arguments !\n", 34);
	else if (x == 10)
		write(2, "Error\nYour argument has a wrong extension !\n", 44);
	else if (x == 11)
		write(2, "Error\nYour path is not practicable !\n", 37);
	exit(EXIT_FAILURE);
}

int	ft_exit_game(t_game *game, int x)
{
	if (x == 1)
		write(2, "The path of your image is wrong !\n", 35);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

void	print_map(char **map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][++x])
			write(1, &map[y][x], 1);
		write(1, "\n", 1);
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
