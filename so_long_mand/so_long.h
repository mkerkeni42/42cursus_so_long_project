/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:51:36 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/28 10:36:00 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"

# define UP 119 //13
# define DOWN 115 //1
# define LEFT 97 //0
# define RIGHT 100 //2

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
	int			moov;
}	t_game;

int		main(int ac, char **av);

t_map	*parse_map(char *av);

void	check_rectangle(char *line, size_t len);
void	check_map_closed(t_map *map);
void	check_collectible(t_map *map);
void	check_element(t_map *map);

void	handle_error(int x);
int		ft_exit_game(t_game *game, int x);
int		count_char(char *str, char c);
void	print_map(char **map);
void	get_position(t_game *game);
void	free_map(char **map);

void	check_path(t_map *map);

void	set_background(t_game game, char **map);
void	set_walls(t_game game, char **map);
void	set_start(t_game game, char **map);
void	set_end(t_game game, char **map);
void	set_collectible(t_game *game, char **map);

void	go_down(t_game *game);
void	go_up(t_game *game);
void	go_right(t_game *game);
void	go_left(t_game *game);

int		deal_key(int key, t_game *game);
void	set_back(t_game *game);
void	get_path(t_game *game, int key);

#endif
