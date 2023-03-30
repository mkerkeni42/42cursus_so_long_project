/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:15:17 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/30 11:35:06 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_background(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->sprite.path = "so_long_bonus/so_long_images_xpm/yellow_square.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x])
			mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
				64 * x, 64 * y);
	}
}

void	set_walls(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->sprite.path = "so_long_bonus/so_long_images_xpm/gaufre.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x])
			if (game->map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
					game->sprite.addr, 64 * x, 64 * y);
	}
}

void	set_start(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->sprite.path = "so_long_bonus/so_long_images_xpm/sprite_front.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x])
			if (game->map->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, \
					game->sprite.addr, 64 * x, 64 * y);
	}
}

void	set_end(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->sprite.path = "so_long_bonus/so_long_images_xpm/red_car.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x])
			if (game->map->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
					game->sprite.addr, 64 * x, 64 * y);
	}
}

void	set_collectible(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->collect = 0;
	game->sprite.path = "so_long_bonus/so_long_images_xpm/ice_cream.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x])
		{
			if (game->map->map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, \
				game->sprite.addr, 64 * x, 64 * y);
				game->collect++;
			}
		}
	}
}
