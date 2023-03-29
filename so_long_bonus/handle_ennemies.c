/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ennemies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:41:54 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/29 12:34:00 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_enemies(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->sprite.path = "so_long_bonus/so_long_images_xpm/brocoli_droit.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x])
		{
			if (game->map->map[y][x] == 'A')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->sprite.addr, 64 * x, 64 * y);
		}
	}
}

void	get_path_life(t_game *game)
{	
	if (game->enemy == 0)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/full_life.xpm";
	else if (game->enemy == 1)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/two_lifes.xpm";
	else if (game->enemy == 2)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/one_life.xpm";
}

void	set_life(t_game *game)
{
	get_path_life(game);
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	mlx_put_image_to_window(game->mlx, game->win, \
		game->sprite.addr, game->size_win.x - 200, 0);
}

void	check_enemy(t_game *game, int key)
{
	if (game->map->map[game->sprite_pos.y][game->sprite_pos.x] == 'A')
	{
		game->enemy++;
		if (game->enemy >= 3)
		{
			set_big_image(game, 2);
			if (key == 36 || key == 17)
				ft_exit_game(game, 0);
		}
		set_life(game);
	}
}
