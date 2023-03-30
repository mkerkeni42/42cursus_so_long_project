/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:41:54 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/30 14:46:06 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_back_enemy(t_game *game, int x, int y)
{
	game->sprite.path = "so_long_bonus/so_long_images_xpm/yellow_square.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
			64 * x, 64 * y);
}

void	get_path_enemy(t_game *game, int x)
{
	if (x == 0)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/broco_left.xpm";
	else if (x == 1)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/broco.xpm";
	else if (x == 2)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/broco_right.xpm";
	else if (x == 3)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/broco.xpm";
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
}

void	print_enemy(t_game *game, int img, int x, int y)
{
	if (game->frame % 1000 == 0)
	{
		set_back_enemy(game, x, y);
		get_path_enemy(game, img);
		mlx_put_image_to_window(game->mlx, game->win, \
			game->sprite.addr, 64 * x, 64 * y);
	}
}

void	set_enemies(t_game *game)
{
	static int	img = 0;
	int			x;
	int			y;

	y = -1;
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x])
		{
			if (game->map->map[y][x] == 'A')
				print_enemy(game, img, x, y);
		}
	}
	if (game->frame % 1000 == 0)
	{
		img++;
		if (img == 4)
			img = 0;
	}
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
