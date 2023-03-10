/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:34:01 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/10 15:57:17 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!ft_strnstr(file_name, ".ber", ft_strlen(file_name)))
		handle_error(10);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;

	if (ac != 2)
		handle_error(9);
	check_file_name(av[1]);
	parse_map(av[1]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1800, "so long");
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	//mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	//system("leaks so_long");
	return (EXIT_SUCCESS);
}
