/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:15:17 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/24 13:31:02 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_background(t_game game, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game.sprite.path = "so_long_mand/so_long_images_xpm/yellow_square.xpm";
	game.sprite.addr = mlx_xpm_file_to_image(game.mlx, game.sprite.path, \
		&game.sprite.width, &game.sprite.height);
	if (!game.sprite.addr)
		ft_exit_game(&game, 1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			mlx_put_image_to_window(game.mlx, game.win, game.sprite.addr, \
				game.sprite.width * x, game.sprite.width * y);
			x++;
		}
		y++;
	}
}

void	set_walls(t_game game, char **map)
{
	int	x;
	int	y;

	y = 0;
	game.sprite.path = "so_long_mand/so_long_images_xpm/gaufre.xpm";
	game.sprite.addr = mlx_xpm_file_to_image(game.mlx, game.sprite.path, \
		&game.sprite.width, &game.sprite.height);
	if (!game.sprite.addr)
		ft_exit_game(&game, 1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.sprite.addr, \
					game.sprite.width * x, game.sprite.width * y);
			}
			x++;
		}
		y++;
	}
}

void	set_end(t_game game, char **map)
{
	int	x;
	int	y;

	y = 0;
	game.sprite.path = "so_long_mand/so_long_images_xpm/red_car.xpm";
	game.sprite.addr = mlx_xpm_file_to_image(game.mlx, game.sprite.path, \
		&game.sprite.width, &game.sprite.height);
	if (!game.sprite.addr)
		ft_exit_game(&game, 1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.sprite.addr, \
					game.sprite.width * x, game.sprite.width * y);
			}
			x++;
		}
		y++;
	}
}

void	set_start(t_game game, char **map)
{
	int	x;
	int	y;

	y = 0;
	game.sprite.path = "so_long_mand/so_long_images_xpm/sprite_front.xpm";
	game.sprite.addr = mlx_xpm_file_to_image(game.mlx, game.sprite.path, \
		&game.sprite.width, &game.sprite.height);
	if (!game.sprite.addr)
		ft_exit_game(&game, 1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.sprite.addr, \
					game.sprite.width * x, game.sprite.width * y);
			}
			x++;
		}
		y++;
	}
}

void	set_collectible(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	game->collect = 0;
	game->sprite.path = "so_long_mand/so_long_images_xpm/ice_cream.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, \
				game->sprite.addr, 64 * x, 64 * y);
				game->collect++;
			}
			x++;
		}
		y++;
	}
}
