/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:00:18 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/31 13:23:25 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	get_position(t_game	*game)
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

static int	render_next_frame(t_game *game)
{
	game->frame++;
	if (game->start == 1 && game->enemy < 3 && game->end < 1)
		set_enemies(game);
	if (game->frame > 2147483646)
		game->frame = 0;
	return (0);
}

static void	init_vars(t_game *game)
{
	game->move = 1;
	game->enemy = 0;
	game->start = 0;
	game->end = 0;
	game->frame = 0;
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
	init_vars(&game);
	get_position(&game);
	mlx_key_hook(game.win, deal_key, &game);
	mlx_hook(game.win, 17, 0, ft_exit_game, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
