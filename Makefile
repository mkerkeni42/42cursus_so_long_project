# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 12:41:15 by mkerkeni          #+#    #+#              #
#    Updated: 2023/03/29 12:11:34 by mkerkeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = Libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINKS = -I /usr/local/lib -lmlx -framework OpenGL -framework AppKit
#ifdef DEBUG
CFLAGS += -fsanitize=address -g3
#endif

SRCS = 	./so_long_mand/main.c \
		./so_long_mand/parsing_map.c \
		./so_long_mand/check_map.c \
		./so_long_mand/so_long_utils.c \
		./so_long_mand/check_path.c \
		./so_long_mand/set_sprites.c \
		./so_long_mand/deal_hook.c \
		./so_long_mand/make_moovs.c \

SRCS_BONUS = 	./so_long_bonus/main_bonus.c \
				./so_long_bonus/parsing_map_bonus.c \
				./so_long_bonus/check_map_bonus.c \
				./so_long_bonus/so_long_utils_bonus.c \
				./so_long_bonus/check_path_bonus.c \
				./so_long_bonus/set_sprites_bonus.c \
				./so_long_bonus/deal_hook_bonus.c \
				./so_long_bonus/make_moovs_bonus.c \
				./so_long_bonus/handle_ennemies.c \

OBJS_MAIN = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifndef BONUS
OBJS = $(OBJS_MAIN)
else
OBJS = $(OBJS_BONUS)
endif

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "	Compilation in progress..."
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(CFLAGS) $(LINKS) -o $(NAME) $^ $(LIBFT)libft.a
	@echo "	Compiled !"

bonus : fclean
	@$(MAKE) BONUS=1

debug:
	@$(MAKE) DEBUG=1

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f Libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus