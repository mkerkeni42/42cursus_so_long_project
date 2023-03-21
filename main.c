/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:34:01 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/21 16:44:11 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
	set_collectible(game, map->map);
	game.count = 0;
	game.map = map;
	mlx_key_hook(game.win, deal_key, &game);
	mlx_loop(game.mlx);
	//system("leaks so_long");
	return (EXIT_SUCCESS);
}
