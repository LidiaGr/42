# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/17 21:38:47 by ttarsha           #+#    #+#              #
#    Updated: 2020/09/19 11:12:50 by ttarsha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a
NASM		= nasm
NASM_FLAGS	= -f macho64
OBJS_DIR	= bin/
SRCS_DIR	= srcs/
SRCS		=	ft_strlen \
				ft_strcpy \
				ft_strcmp \
				ft_write \
				ft_read \
				ft_strdup
OBJS		= $(addprefix $(OBJS_DIR), $(SRCS:=.o))

TEST		= tester
CC			= gcc
GCC_FLAGS	= -g -Wall -Werror -Wextra
INCLUDES	= -I inc/
TEST_DIR	= test/
TEST_SRCS	= main
TEST_OBJS	= $(addprefix $(OBJS_DIR), $(TEST_SRCS:=.o))



all:			$(OBJS_DIR) $(NAME)	

$(OBJS_DIR):	
	mkdir -p	$(OBJS_DIR)

$(NAME):		$(OBJS)
	ar rc		$(NAME) $?
	ranlib		$(NAME)

$(OBJS):		$(OBJS_DIR)%.o: $(SRCS_DIR)%.s	
	$(NASM)		$(NASM_FLAGS) $< -o $@

$(TEST):		$(OBJS_DIR) $(NAME) $(TEST_OBJS)
	$(CC)		$(GCC_FLAGS) $(TEST_OBJS) $(INCLUDES) -L. -lasm -o $(TEST)

$(TEST_OBJS):	$(OBJS_DIR)%.o: $(TEST_DIR)%.c
	$(CC)		$(GCC_FLAGS) $(INCLUDES) -c $< -o $@ 

test:			$(TEST)
	./$(TEST)

clean:
	rm -rf		$(OBJS_DIR)

fclean:			clean
	rm -f		$(NAME) $(TEST)

re:				fclean all


.PHONY: all clean fclean re test