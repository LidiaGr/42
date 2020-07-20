# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttarsha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 11:44:36 by ttarsha           #+#    #+#              #
#    Updated: 2020/07/13 22:44:54 by ttarsha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC = ft_printf.h libft/libft.h

FT_PRINTF_SRC = ft_printf.c ft_parsing.c \
				processing/ft_fill_precision.c \
				processing/ft_print_with_width_and_flags.c \
				processing/ft_process_c.c processing/ft_process_str.c \
				processing/ft_process_d_i.c processing/ft_process_u.c \
				processing/ft_process_percent.c processing/ft_process_x.c \
				processing/ft_process_pointer.c

LIBFT_PATH = libft/

LIBFT_SRC = ft_strlen.c ft_isdigit.c ft_strdup.c ft_atoi.c ft_itoa.c \
			ft_calloc.c ft_memset.c ft_strjoin.c ft_substr.c ft_strlcpy.c \
			ft_itoa_base16_bonus.c ft_toupper.c

OBJ = $(FT_PRINTF_SRC:c=o)

OBJ += $(addprefix $(LIBFT_PATH),$(LIBFT_SRC:.c=.o))

%.o:%.c $(INC)
	gcc -Wall -Werror -Wextra -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	
clean:
	rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re