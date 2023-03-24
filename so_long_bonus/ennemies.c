/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:41:54 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/24 13:44:27 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_enemies(t_game *game, char **map)
{
	int	x;
	int	y;

	y = -1;
	game->enemy = 0;
	game->sprite.path = "so_long_bonus/so_long_images_xpm/brocoli_droit.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'A')
			{
				mlx_put_image_to_window(game->mlx, game->win, \
				game->sprite.addr, 64 * x, 64 * y);
				game->enemy++;
			}
		}
	}
}
