# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 21:53:03 by marrodri          #+#    #+#              #
#    Updated: 2019/09/23 21:53:05 by marrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

CFLAGS += -Wall -Wextra -Werror
# CFLAGS += -I ./libft
RM = rm -f

SRC = checker_main.c check_stack.c ps_ft.c \
	ps_in_ch.c ps_listft.c push_ft.c rot_ft.c \
	sort_stack.c swap_ft.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

.PHONY = all clean fclean re

all: $(NAME1)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@ -g
 
$(LIBFT):
	@make -C libft

$(NAME1): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME1)

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME1)
	@make -C libft fclean

re: fclean all