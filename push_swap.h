
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include "./libft/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	swap(t_list *stack);
void	swap_s(t_list *stack_a, t_list *stack_b);
void	push_a(t_list *stack_a, t_list *stack_b);
void	push_b(t_list *stack_a, t_list *stack_b);
void	rot(t_list *stack);
void	rot_r(t_list *stack_a, t_list *stack_b);
void	rrot(t_list *stack);
void	rrot_r(t_list *stack_a, t_list *stack_b);

int		check_stack(t_list *stack);
int		check_stacks(t_list *stack_a, t_list *stack_b);
void	sort_stacks(t_list *stack_a, t_list *stack_b, char **instr);

#endif