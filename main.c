/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:34:01 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/02 13:41:14 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*int	deal_key(int key, void *param)
{
	if (key == 13) // haut
	{
		
	}
	else if (key == 1) // bas
	{
		
	}
	else if (key == 0) // gauche
	{
		
	}
	else if (key == 2) // droite
	{
		
	}
	printf("%d\n", key);
	return (0);
}*/

int	main(void)
{
	//void	*mlx_ptr;
	//void	*win_ptr;
	int		fd;
	
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	if (parse_map(fd) == 0)
	{
		close(fd);
		return(EXIT_FAILURE);
	}
	printf("check is ok");
	//mlx_ptr = mlx_init();
	//win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so long");
	//mlx_key_hook(win_ptr, deal_key, (void *)0);
	//mlx_loop(mlx_ptr);
	return (EXIT_SUCCESS);
}
