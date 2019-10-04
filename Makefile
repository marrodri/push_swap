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
RM = rm -f

CH_SRC = checker_main.c

SRC = checker_main.c check_stack.c  \
	psch_input.c psch_listft.c push_ft.c rot_ft.c \
	sort_stack_tb.c swap_ft.c psch_free.c \

PS_SRC = ps_main.c ps_act_ft.c ps_set_sort.c ps_sta_ft.c \
		ps_stb_f.c sort_a_ft.c sort_b_ft.c sort_both.c 

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

.PHONY = all clean fclean re

all: $(NAME1)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@ -g
 
$(LIBFT):
	@make -C libft

$(NAME1): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME1) -g

clean:
	@echo "cleaning .o files"
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME1)
	@make -C libft fclean

re: fclean all