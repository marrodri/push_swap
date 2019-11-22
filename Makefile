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

SRC = check_stack.c psch_input.c psch_listft.c\
		push_ft.c rot_ft.c sort_stack_tb.c \
		swap_ft.c psch_free.c  

PS_SRC = ps_main.c ps_act_ft.c ps_set_sort.c ps_sta_ft.c \
		ps_stb_ft.c sort_a_ft.c sort_b_ft.c sort_both.c ps_mergeSt.c\
		ps_valInd_ft.c ps_sortedSt_ft.c ps_rraAct.c ps_debugger.c\
		ps_stckRotSort.c stck_chunk.c ps_instComp.c

SRC_OBJ = $(SRC:.c=.o)

PS_OBJ = $(PS_SRC:.c=.o)

CH_OBJ = checker_main.o

LIBFT = ./libft/libft.a

.PHONY = all clean fclean re

all: $(NAME2) $(NAME1)

$(SRC_OBJ): %.o: %.c 
	@gcc -c $(CFLAGS) $< -o $@ -g

$(CH_OBJ): %.o: %.c 
	@gcc -c $(CFLAGS) $< -o $@ -g

$(PS_OBJ):  %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@ -g

$(LIBFT):
	@make -C libft

$(NAME1): $(LIBFT) $(CH_OBJ) $(SRC_OBJ)
	@gcc $(CH_OBJ) $(SRC_OBJ) $(LIBFT)  -o $(NAME1) -g

$(NAME2): $(LIBFT) $(PS_OBJ) $(SRC_OBJ)
	gcc $(PS_OBJ) $(SRC_OBJ) $(LIBFT) -o $(NAME2) -g
	#   -fsanitize=address

clean:
	@echo "cleaning .o files"
	@rm -rf $(CH_OBJ) $(PS_OBJ) $(SRC_OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME1) $(NAME2)
	@make -C libft fclean

re: fclean all
