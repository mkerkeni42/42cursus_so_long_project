/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:34:01 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/22 16:07:11 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	get_position(t_game	*game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'P')
			{
				game->sprite_pos.x = x;
				game->sprite_pos.y = y;
			}
			x++;
		}
		y++;
	}
}

static void	check_file_name(char *file_name)
{
	if (!ft_strnstr(file_name, ".ber", ft_strlen(file_name)))
		handle_error(10);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_map	*map;

	if (ac != 2)
		handle_error(9);
	check_file_name(av[1]);
	map = parse_map(av[1]);
	game.mlx = mlx_init();
	game.size_win.x = map->tot_col * 64;
	game.size_win.y = map->tot_row * 64;
	game.win = mlx_new_window(game.mlx, game.size_win.x, \
		game.size_win.y, "so long");
	set_background(game, map->map);
	set_walls(game, map->map);
	set_end(game, map->map);
	set_start(game, map->map);
	set_collectible(&game, map->map);
	game.map = map;
	get_position(&game);
	mlx_key_hook(game.win, deal_key, &game);
	mlx_hook(game.win, 17, 0, ft_exit_game, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
