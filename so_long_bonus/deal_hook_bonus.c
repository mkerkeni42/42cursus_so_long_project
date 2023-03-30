/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:20:38 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/30 15:52:41 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	end_game(t_game *game, int key)
{
	if (game->map->map[game->sprite_pos.y][game->sprite_pos.x] == 'E')
	{
		set_big_image(game, 1);
		game->end++;
		if (key == 36 || key == 17)
			ft_exit_game(game, 0);
	}
}

void	get_path(t_game *game, int key)
{
	if (key == 1)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/sprite_front.xpm";
	else if (key == 13)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/sprite_back.xpm";
	else if (key == 0)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/sprite_left.xpm";
	else if (key == 2)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/sprite_right.xpm";
	//else if (key == 3)
	
}

void	set_back(t_game *game)
{
	game->sprite.path = "so_long_bonus/so_long_images_xpm/yellow_square.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
		64 * game->sprite_pos.x, 64 * game->sprite_pos.y);
	if (game->map->map[game->sprite_pos.y][game->sprite_pos.x] == 'E')
		set_end(game);
	if (game->map->map[game->sprite_pos.y][game->sprite_pos.x] == 'A')
		set_enemies(game);
	set_life(game);
}

void	set_game(t_game *game)
{
	game->start++;
	set_background(game);
	set_walls(game);
	set_start(game);
	set_end(game);
	set_collectible(game);
	set_enemies(game);
	set_life(game);
	mlx_string_put(game->mlx, game->win, 0, 42, 12, "Moves = 0");
}

int	deal_key(int key, t_game *game)
{
	if (key == 36 && game->start == 0)
		set_game(game);
	if (key == 1 && game->start == 1 && game->enemy < 3 && game->end < 1
		&& game->map->map[game->sprite_pos.y + 1][game->sprite_pos.x] != '1')
		go_down(game);
	else if (key == 13 && game->start == 1 && game->enemy < 3 && game->end < 1
		&& game->map->map[game->sprite_pos.y - 1][game->sprite_pos.x] != '1')
		go_up(game);
	else if (key == 0 && game->start == 1 && game->enemy < 3 && game->end < 1
		&& game->map->map[game->sprite_pos.y][game->sprite_pos.x - 1] != '1')
		go_left(game);
	else if (key == 2 && game->start == 1 && game->enemy < 3 && game->end < 1
		&& game->map->map[game->sprite_pos.y][game->sprite_pos.x + 1] != '1')
		go_right(game);
	else if (key == 53)
		ft_exit_game(game, 0);
	check_enemy(game, key);
	if (game->collect == 0)
		end_game(game, key);
	return (0);
}
