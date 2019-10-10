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

SRC = check_stack.c  \
	psch_input.c psch_listft.c push_ft.c rot_ft.c \
	sort_stack_tb.c swap_ft.c psch_free.c \

PS_SRC = ps_main.c ps_act_ft.c ps_set_sort.c ps_sta_ft.c \
		ps_stb_ft.c sort_a_ft.c sort_b_ft.c sort_both.c 

PS_OBJ += $(PS_SRC:.c=.o)
PS_OBJ += $(SRC:.c=.o)

CH_OBJ += checker_main.o
CH_OBJ += $(SRC:.c=.o)

LIBFT = ./libft/libft.a

.PHONY = all clean fclean re

all: $(NAME2)

# $(CH_OBJ): %.o: %.c
# 	@gcc -c $(CFLAGS) $< -o $@ -g

$(PS_OBJ):  %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@ -g

$(LIBFT):
	@make -C libft

# $(NAME1): $(LIBFT) $(CH_OBJ)
# 	@gcc $(CH_OBJ) $(LIBFT) -o $(NAME1) -g

$(NAME2): $(LIBFT) $(PS_OBJ)
	gcc $(PS_OBJ) $(LIBFT) -o $(NAME2) -g

clean:
	@echo "cleaning .o files"
	@rm -rf $(CH_OBJ) $(PS_OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME1)
	@make -C libft fclean

re: fclean all


# use this for compiling the push_swap program
# gcc ps_main.c ps_sta_ft.c ps_stb_ft.c psch_input.c check_stack.c rot_ft.c swap_ft.c psch_listft.c push_ft.c ps_set_sort.c ps_act_ft.c sort_a_ft.c sort_b_ft.c sort_both.c libft/libft.a