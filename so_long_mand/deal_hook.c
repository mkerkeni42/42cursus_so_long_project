/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:20:38 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/29 13:14:16 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_path(t_game *game, int key)
{
	if (key == 1)
		game->sprite.path = "so_long_mand/so_long_images_xpm/sprite_front.xpm";
	else if (key == 13)
		game->sprite.path = "so_long_mand/so_long_images_xpm/sprite_back.xpm";
	else if (key == 0)
		game->sprite.path = "so_long_mand/so_long_images_xpm/sprite_left.xpm";
	else if (key == 2)
		game->sprite.path = "so_long_mand/so_long_images_xpm/sprite_right.xpm";
}

void	set_back(t_game *game)
{
	game->sprite.path = "so_long_mand/so_long_images_xpm/yellow_square.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
		64 * game->sprite_pos.x, 64 * game->sprite_pos.y);
	if (game->map->map[game->sprite_pos.y][game->sprite_pos.x] == 'E')
		set_end(*game, game->map->map);
}

int	deal_key(int key, t_game *game)
{
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
	else if (key == 53)
		ft_exit_game(game, 0);
	if (game->collect == 0)
	{
		if (game->map->map[game->sprite_pos.y][game->sprite_pos.x] == 'E')
		{
			ft_printf("%d\n", game->moov++);
			ft_exit_game(game, 0);
		}
	}
	return (0);
}
