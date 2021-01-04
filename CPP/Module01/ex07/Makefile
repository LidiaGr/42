# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/03 13:18:22 by ttarsha           #+#    #+#              #
#    Updated: 2020/12/07 22:21:12 by ttarsha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= replace

OBJS_DIR	= bin/
SRCS_DIR	= ./
SRCS		= main
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:=.o))

CC			= clang++
GCC_FLAGS	= -g -Wall -Wextra -Werror
INCLUDES	= -I inc/



all:			$(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p	$(OBJS_DIR)

$(NAME):		$(OBJS)
	$(CC) 		-g $(OBJS) -o $(NAME)

$(OBJS):		$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	$(CC)		$(GCC_FLAGS) $(INCLUDES) -c $< -o $@


clean:
	rm -rf		$(OBJS_DIR)

fclean:			clean
	rm -f		$(NAME) *.replace

re:				fclean all


.PHONY: all clean fclean re