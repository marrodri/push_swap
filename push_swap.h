/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:30:54 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/19 16:30:56 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define PS_FLAG { 'v', 'g', 'f'}
# define PS_INST { "sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"}
# define PS_INS_SZ 11
# define PS_FL_SZ 3
# include "./libft/libft.h"
# include "./libft/ft_printf.h"

typedef	struct	s_flag
{
		int		flag[3];
}				t_flag;

typedef struct	s_app
{
	char	**instr;
	int		*stck;
	int		len_inst;
	int		len_stck;

}				t_app;

void	swap(t_list **stack);
void	swap_s(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_a, t_list **stack_b);
void	rot(t_list **stack);
void	rot_r(t_list **stack_a, t_list **stack_b);
void	rrot(t_list **stack);
void	rrot_r(t_list **stack_a, t_list **stack_b);

int		read_instr(int fd, t_app **app);
int		check_arg(char **argv, t_app **app);

int		check_stack(t_list *stack);
int		check_stacks(t_list *stack_a, t_list *stack_b);
void	sort_stacks(t_list *stack_a, t_list *stack_b, char **instr);

t_list 	*ft_set_node(int num, void *cont, size_t size);
void	add_new_elem(t_list **alist, int num);
#endif
