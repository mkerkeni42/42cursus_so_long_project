/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:51:36 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/04/03 09:30:26 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"

typedef struct s_map {
	int		tot_row;
	int		tot_col;
	int		x;
	int		y;
	char	**map;
}	t_map;

typedef struct s_position {
	int	x;
	int	y;
}	t_position;

typedef struct s_image {
	void		*img_ptr;
	char		*addr;
	t_position	size;
	int			width;
	int			height;
	char		*path;
}	t_image;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_position	size_win;
	t_image		sprite;
	t_position	sprite_pos;
	t_map		*map;
	int			collect;
	int			enemy;
	int			move;
	int			end;
	int			start;
	int			frame;
	char		*back;
	int			key;
	int			game_over;
}	t_game;

int		main(int ac, char **av);

t_map	*parse_map(char *av);

void	check_rectangle(char *line, size_t len);
void	check_map_closed(t_map *map);
void	check_collectible(t_map *map);
void	check_element(t_map *map);

void	set_big_image(t_game *game, int x);
void	get_path_big_image(t_game *game, int x);

void	check_path(t_map *map);

int		deal_key(int key, t_game *game);
void	set_game(t_game *game);
void	set_back(t_game *game);
void	get_path(t_game *game, int key);

void	set_background(t_game *game);
void	set_walls(t_game *game);
void	set_start(t_game *game);
void	set_end(t_game *game);
void	set_collectible(t_game *game);

void	go_down(t_game *game);
void	go_up(t_game *game);
void	go_right(t_game *game);
void	go_left(t_game *game);

void	handle_error(int x);
int		ft_exit_game(t_game *game, int x);
void	print_map(char **map);
void	free_map(char **map);

void	set_enemies(t_game *game);
void	check_enemy(t_game *game);

void	get_path_life(t_game *game);
void	set_life(t_game *game);

#endif
