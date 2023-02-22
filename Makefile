# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 12:41:15 by mkerkeni          #+#    #+#              #
#    Updated: 2023/02/22 12:41:44 by mkerkeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_PRINTF = ft_printf/
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBFT_PRINTF)libftprintf.a

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_PRINTF)

fclean: clean
	rm -f $(NAME)
	rm -f ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re