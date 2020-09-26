# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 11:44:36 by ttarsha           #+#    #+#              #
#    Updated: 2020/09/15 16:20:22 by ttarsha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I./mlx -I./libft
LIBS = -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS =  ./engine/main.c \
		./parser/parser.c ./parser/parse_res.c ./parser/parse_tex.c \
		./parser/parse_color.c ./parser/parse_map.c ./parser/parse_player.c \
		./parser/create_map_tab.c ./parser/tools.c ./parser/gnl.c \
		./engine/draw.c ./engine/events.c ./engine/inits.c \
		./engine/rays.c ./engine/screenshot.c ./engine/sprite.c

OBJS = $(SRCS:c=o)

all: $(NAME)

mlx:
	@make -C ./mlx 

libft:
	@make bonus -C ./libft

$(NAME): mlx libft $(OBJS)
	@$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

%.o:%.c cub.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make clean -C libft
	make clean -C mlx
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	rm -f screenshot.bmp

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus libft mlx bonus
	