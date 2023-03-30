/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_big_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:11:51 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/30 13:13:17 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_path_big_image(t_game *game, int x)
{
	if (x == 0)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/open_image.xpm";
	else if (x == 1)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/win_image.xpm";
	else if (x == 2)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/game_over.xpm";
}

void	set_big_image(t_game *game, int x)
{
	get_path_big_image(game, x);
	game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
		&game->sprite.width, &game->sprite.height);
	if (!game->sprite.addr)
		ft_exit_game(game, 1);
	mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, 0, 0);
}
