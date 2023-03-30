/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moovs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:45:47 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/29 13:14:44 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_down(t_game *game)
{
	set_back(game);
	game->sprite_pos.y += 1;
	if (game->map->map[game->sprite_pos.y][game->sprite_pos.x] == 'C')
	{
		game->map->map[game->sprite_pos.y][game->sprite_pos.x] = '0';
		game->collect--;
	}
	get_path(game, 1);
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
		64 * game->sprite_pos.x, 64 * (game->sprite_pos.y));
	ft_printf("%d\n", game->moov++);
}

void	go_up(t_game *game)
{
	set_back(game);
	game->sprite_pos.y -= 1;
	if (game->map->map[game->sprite_pos.y][game->sprite_pos.x] == 'C')
	{
		game->map->map[game->sprite_pos.y][game->sprite_pos.x] = '0';
		game->collect--;
	}
	get_path(game, 13);
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
		64 * game->sprite_pos.x, 64 * (game->sprite_pos.y));
	ft_printf("%d\n", game->moov++);
}

void	go_left(t_game *game)
{
	set_back(game);
	game->sprite_pos.x -= 1;
	if (game->map->map[game->sprite_pos.y][game->sprite_pos.x] == 'C')
	{
		game->map->map[game->sprite_pos.y][game->sprite_pos.x] = '0';
		game->collect--;
	}
	get_path(game, 0);
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
		64 * (game->sprite_pos.x), 64 * game->sprite_pos.y);
	ft_printf("%d\n", game->moov++);
}

void	go_right(t_game *game)
{
	set_back(game);
	game->sprite_pos.x += 1;
	if (game->map->map[game->sprite_pos.y][game->sprite_pos.x] == 'C')
	{
		game->map->map[game->sprite_pos.y][game->sprite_pos.x] = '0';
		game->collect--;
	}
	get_path(game, 2);
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
		64 * (game->sprite_pos.x), 64 * game->sprite_pos.y);
	ft_printf("%d\n", game->moov++);
}
