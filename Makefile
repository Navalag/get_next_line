# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agalavan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 12:38:06 by agalavan          #+#    #+#              #
#    Updated: 2017/12/21 12:38:10 by agalavan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

FLAGS = -Wall -Wextra -Werror -I. -c

SRCS = 	main.c\
		get_next_line.c\

HEADER = get_next_line.h

# LIBFT = ~/projects/get_next_line/test_folder/libft/libft.a
L_DIR = libft

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ~/projects/get_next_line/test_folder/libft
	gcc $(FLAGS) $(SRCS) $(HEADER)
	gcc $(OBJS) -o $(NAME) -I $(L_DIR) -L $(L_DIR) -lft

%.o: %.c
	gcc $(FLAGS) $<

clean:
	-rm -f $(OBJS) *.gch

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
