/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:32:58 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/02/23 14:13:44 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

char	*get_next_line(int fd);
//size_t	ft_strlen(const char *s);
//char	*ft_strchr(char *s, int c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin_gnl(char *s1, char *s2, int x);
//char	*ft_substr(char const *s, unsigned int start, size_t len);

typedef struct s_lst
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];
	char	*final;
}	t_lst;

#endif
