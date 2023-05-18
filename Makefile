# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharsune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 17:01:10 by sharsune          #+#    #+#              #
#    Updated: 2023/02/13 17:01:15 by sharsune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

SRC = push_swap.c swap.c push.c rotates.c sort.c create_stacks.c errors.c checks.c errors_2.c

OSRC = $(SRC:%.c=%.o)

WWW = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OSRC) $(LIBFT)
	cc $(WWW) $(OSRC) -L libft/ -lft -o $(NAME)

clean:
	rm -f $(OSRC)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/$(LIBFT)

%.o: %.c
	cc $(WWW)  -g -c -o  $@ $^

re: fclean all

.PHONY: all clean fclean re
