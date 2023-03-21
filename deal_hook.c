/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:20:38 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/21 16:40:13 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_path(t_game *game, int key)
{
	if (key == 1)
	{
		game->map->map[game->sprite_pos.y + 1][game->sprite_pos.x] = 'P';
		game->sprite.path = "so_long_images_xpm/emir_front.xpm";
	}
	else if (key == 13)
	{
		game->map->map[game->sprite_pos.y - 1][game->sprite_pos.x] = 'P';
		game->sprite.path = "so_long_images_xpm/emir_front.xpm";
	}
	else if (key == 0)
	{
		game->map->map[game->sprite_pos.y][game->sprite_pos.x - 1] = 'P';
		game->sprite.path = "so_long_images_xpm/sprite_left1.xpm";
	}
	else if (key == 2)
	{
		game->map->map[game->sprite_pos.y][game->sprite_pos.x + 1] = 'P';
		game->sprite.path = "so_long_images_xpm/sprite_right2.xpm";
	}
}

static void	set_back(t_game *game)
{
	game->sprite.path = "so_long_images_xpm/yellow_square.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
		game->sprite.width * game->sprite_pos.x, game->sprite.width * game->sprite_pos.y);
	game->map->map[game->sprite_pos.y][game->sprite_pos.x] = '0';
}

static void	go_down(t_game *game)
{
	set_back(game);
	if (game->map->map[game->sprite_pos.y + 1][game->sprite_pos.x] == 'C')
		game->count++;
	get_path(game, 1);
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
		64 * game->sprite_pos.x, 64 * (game->sprite_pos.y + 1));
}

static void	go_up(t_game *game)
{
	set_back(game);
	if (game->map->map[game->sprite_pos.y - 1][game->sprite_pos.x] == 'C')
		game->count++;
	get_path(game, 13);
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
		64 * game->sprite_pos.x, 64 * (game->sprite_pos.y - 1));	
}

static void	go_left(t_game *game)
{
	set_back(game);
	if (game->map->map[game->sprite_pos.y][game->sprite_pos.x - 1] == 'C')
		game->count++;
	get_path(game, 0);
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
		64 * (game->sprite_pos.x - 1), 64 * game->sprite_pos.y);
}

static void	go_right(t_game *game)
{
	set_back(game);
	if (game->map->map[game->sprite_pos.y][game->sprite_pos.x + 1] == 'C')
		game->count++;
	get_path(game, 2);
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
		64 * (game->sprite_pos.x + 1), 64 * game->sprite_pos.y);	
}

int	deal_key(int key, t_game *game)
{
	get_position(game);
	if (key == 1 
		&& game->map->map[game->sprite_pos.y + 1][game->sprite_pos.x] != '1')
		go_down(game);
	else if (key == 13 
		&& game->map->map[game->sprite_pos.y - 1][game->sprite_pos.x] != '1')
		go_up(game);
	else if (key == 0 
		&& game->map->map[game->sprite_pos.y][game->sprite_pos.x - 1] != '1')
		go_left(game);
	else if (key == 2 
		&& game->map->map[game->sprite_pos.y][game->sprite_pos.x + 1] != '1')
		go_right(game);
	if (game->count == game->collect)
	{
		
	}
	//printf("%d\n", key);
	return (0);
}
