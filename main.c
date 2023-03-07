/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:34:01 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/07 16:22:04 by mkerkeni         ###   ########.fr       */
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
static void	check_file_name(char *file_name)
{
	if (!ft_strnstr(file_name, ".ber", 4))
	{
		printf("retour de strnstr = %p\n", ft_strnstr(file_name, ".ber", 4));
		printf("passed here\n");
		handle_error(10);
	}
}

int	main(int ac, char **av)
{
	//void	*mlx_ptr;
	//void	*win_ptr;

	if (ac != 2)
		handle_error(9);
	check_file_name(av[1]);
	get_map(av[1]);
	//mlx_ptr = mlx_init();
	//win_ptr = mlx_new_window(mlx_ptr, 500, 500, "so long");
	//mlx_key_hook(win_ptr, deal_key, (void *)0);
	//mlx_loop(mlx_ptr);
	//system("leaks so_long");
	return (EXIT_SUCCESS);
}
