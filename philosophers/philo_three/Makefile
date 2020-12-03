# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttarsha <ttarsha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 19:25:25 by ttarsha           #+#    #+#              #
#    Updated: 2020/11/23 17:00:39 by ttarsha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo_three

OBJS_DIR	= bin/
SRCS_DIR    = srcs/
SRCS		=	main \
                init \
                init_utils \
                simulation_utils \
                itoa \
                simulation

OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:=.o))

CC			= gcc
GCC_FLAGS	= -g -Wall -Wextra -Werror
INCLUDES	= -I inc/



all:			$(OBJS_DIR) $(NAME)	

$(OBJS_DIR):	
	mkdir -p	$(OBJS_DIR)

$(NAME):		$(OBJS)
	$(CC) 		-g $(OBJS) -o $(NAME)

$(OBJS):		$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC)		$(GCC_FLAGS) $(INCLUDES) -c $< -o $@


clean:
	rm -rf		$(OBJS_DIR)

fclean:			clean
	rm -f		$(NAME) $(TEST)

re:				fclean all


.PHONY: all clean fclean re