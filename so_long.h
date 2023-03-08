/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:51:36 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/08 15:35:38 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_map {
	int		tot_row;
	int		tot_col;
	int		x;
	int		y;
	char	**map;
}	t_map;

int		main(int ac, char **av);

void	parse_map(char *av);

void	check_rectangle(char *line, size_t len);
void	check_map_closed(t_map *map);
void	check_collectible(t_map *map);
void	check_start(t_map *map);
void	check_exit(t_map *map);

void	handle_error(int x);
int		count_char(char *str, char c);
void	print_map(char **map);

void	check_path(t_map *map);

#endif
