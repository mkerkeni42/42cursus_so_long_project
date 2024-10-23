/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_life.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:00:07 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/30 13:02:00 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_path_life(t_game *game)
{	
	if (game->enemy == 0)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/full_life_with_back.xpm";
	else if (game->enemy == 1)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/two_life_with_back.xpm";
	else if (game->enemy == 2)
		game->sprite.path = "so_long_bonus/so_long_images_xpm/one_life_with_back.xpm";
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
