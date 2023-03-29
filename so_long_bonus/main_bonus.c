/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:00:18 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/29 16:00:23 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_position(t_game	*game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x])
		{
			if (game->map->map[y][x] == 'P')
			{
				game->sprite_pos.x = x;
				game->sprite_pos.y = y;
			}
		}
	}
}

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

int	main(int ac, char **av)
{
	t_game	game;
	t_map	*map;

	if (ac != 2)
		handle_error(9);
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		handle_error(10);
	map = parse_map(av[1]);
	game.mlx = mlx_init();
	game.size_win.x = map->tot_col * 64;
	game.size_win.y = map->tot_row * 64;
	game.win = mlx_new_window(game.mlx, game.size_win.x, \
		game.size_win.y, "SUPER EMIR WORLD");
	game.map = map;
	set_big_image(&game, 0);
	game.moov = 1;
	game.enemy = 0;
	game.start = 0;
	game.end = 0;
	get_position(&game);
	mlx_key_hook(game.win, deal_key, &game);
	mlx_hook(game.win, 17, 0, ft_exit_game, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
