/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:16:48 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/03/02 15:34:14 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(int fd)
{
	int		i;
	int		len;
	char	*line;
	
	i = 0;
	len = 0;
	line = get_next_line(fd);
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	line = get_next_line(fd);
	while (line > 0)
	{
		printf("line = %s\n", line);
		len = ft_strlen(line) - 2;
		if (line[0] != '1' || line[len] != '1')
			return (0);
		free (line);
		line = get_next_line(fd);
	}
	i = 0;
	/*while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}*/
	return (1);
}
