/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:34:01 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/20 16:28:03 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	get_position(t_game	*game, char c)
{
	int	y;
	int	x;
	
	x = 0;
	y = 0;
	game->sprite_pos.x = x;
	game->sprite_pos.y = y;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == c)
			{
				game->sprite_pos.x = x;
				game->sprite_pos.y = y;
			}
			x++;
		}
		y++;
	}
}

int	deal_key(int key, t_game *game)
{
	
	get_position(game, 'P');
	if (key == 1 && game->map->map[game->sprite_pos.y + 1][game->sprite_pos.x] != '1')
	{
		game->sprite.path = "so_long_images_xpm/yellow_square.xpm";
		game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
			&game->sprite.width, &game->sprite.height);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
			game->sprite.width * game->sprite_pos.x, game->sprite.width * game->sprite_pos.y);
		game->map->map[game->sprite_pos.y][game->sprite_pos.x] = 0;
		game->map->map[game->sprite_pos.y + 1][game->sprite_pos.x] = 'P';
		game->sprite.path = "so_long_images_xpm/emir_front.xpm";
		game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
			&game->sprite.width, &game->sprite.height);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
			game->sprite.width * game->sprite_pos.x, game->sprite.width * (game->sprite_pos.y + 1));
	}
	else if (key == 13 && game->map->map[game->sprite_pos.y - 1][game->sprite_pos.x] != '1')
	{
		game->sprite.path = "so_long_images_xpm/yellow_square.xpm";
		game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
			&game->sprite.width, &game->sprite.height);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
			game->sprite.width * game->sprite_pos.x, game->sprite.width * game->sprite_pos.y);
		game->map->map[game->sprite_pos.y][game->sprite_pos.x] = 0;
		game->map->map[game->sprite_pos.y - 1][game->sprite_pos.x] = 'P';
		game->sprite.path = "so_long_images_xpm/emir_front.xpm";
		game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
			&game->sprite.width, &game->sprite.height);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
			game->sprite.width * game->sprite_pos.x, game->sprite.width * (game->sprite_pos.y - 1));
	}
	else if (key == 0 && game->map->map[game->sprite_pos.y][game->sprite_pos.x - 1] != '1')
	{
		game->sprite.path = "so_long_images_xpm/yellow_square.xpm";
		game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
			&game->sprite.width, &game->sprite.height);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
			game->sprite.width * game->sprite_pos.x, game->sprite.width * game->sprite_pos.y);
		game->map->map[game->sprite_pos.y][game->sprite_pos.x] = 0;
		game->map->map[game->sprite_pos.y][game->sprite_pos.x - 1] = 'P';
		game->sprite.path = "so_long_images_xpm/sprite_left1.xpm";
		game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
			&game->sprite.width, &game->sprite.height);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
			game->sprite.width * (game->sprite_pos.x - 1), game->sprite.width * game->sprite_pos.y);
	}
	else if (key == 2 && game->map->map[game->sprite_pos.y][game->sprite_pos.x + 1] != '1')
	{
		game->sprite.path = "so_long_images_xpm/yellow_square.xpm";
		game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
			&game->sprite.width, &game->sprite.height);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
			game->sprite.width * game->sprite_pos.x, game->sprite.width * game->sprite_pos.y);
		game->map->map[game->sprite_pos.y][game->sprite_pos.x] = 0;
		game->map->map[game->sprite_pos.y][game->sprite_pos.x + 1] = 'P';
		game->sprite.path = "so_long_images_xpm/sprite_right2.xpm";
		game->sprite.addr = mlx_xpm_file_to_image(game->mlx, game->sprite.path, \
			&game->sprite.width, &game->sprite.height);
		mlx_put_image_to_window(game->mlx, game->win, game->sprite.addr, \
			game->sprite.width * (game->sprite_pos.x + 1), game->sprite.width * game->sprite_pos.y);
	}
	printf("%d\n", key);
	return (0);
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
	game.map = map;
	mlx_key_hook(game.win, deal_key, &game);
	mlx_loop(game.mlx);
	//system("leaks so_long");
	return (EXIT_SUCCESS);
}
