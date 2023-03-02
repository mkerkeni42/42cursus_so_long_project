# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 12:41:15 by mkerkeni          #+#    #+#              #
#    Updated: 2023/03/02 13:37:44 by mkerkeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = Libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-I /usr/local/lib -lmlx -framework OpenGL \
-framework AppKit \

SRCS = main.c parse_map.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBFT)libft.a

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f Libft/libft.a

re: fclean all

.PHONY: all clean fclean re