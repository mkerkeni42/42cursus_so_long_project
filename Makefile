# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 12:41:15 by mkerkeni          #+#    #+#              #
#    Updated: 2023/03/09 14:30:35 by mkerkeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = Libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINKS = -I /usr/local/lib -lmlx -framework OpenGL -framework AppKit
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

SRCS = main.c parsing_map.c check_map.c so_long_utils.c check_path.c \

OBJS = $(SRCS:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(LINKS) -o $(NAME) $^ $(LIBFT)libft.a

debug:
	$(MAKE) DEBUG=1

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f Libft/libft.a

re: fclean all

.PHONY: all clean fclean re