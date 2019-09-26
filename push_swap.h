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
# define PS_INST { "sa", "ra", "rra", "sb", "rb", "rrb", "ss" , "rr", "rrr", "pa", "pb"}
# define PS_INS_SZ 11
# define PS_INSB_SZ 5
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
	int		*arr_num;
	int		len_inst;
	int		len_stck;
	t_list	*st_a;
	t_list	*st_b;
}				t_app;

typedef int		*t_sort(t_list **stack);
typedef int		*t_sort_both(t_list **stack_a, t_list **stack_b);
int	*swap(t_list **stack);
int	*swap_s(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_a, t_list **stack_b);
int	*rot(t_list **stack);
int	*rot_r(t_list **stack_a, t_list **stack_b);
int	*rrot(t_list **stack);
int	*rrot_r(t_list **stack_a, t_list **stack_b);
int		read_instr(int fd, t_app **app);
int		check_arg(char **argv, t_app **app);
int		check_stack(t_list *stack);
int		check_stacks(t_list *stack_a, t_list *stack_b);
void		sort_stacks(t_list **stack_a, t_list **stack_b, char *instr);
void	set_stack(t_list **stack, t_app *app, int *num);
t_list	*ft_set_node(int num, void *cont, size_t size);
void	add_new_elem(t_list **alist, int num);
int		set_instr(int fd, t_app **app);
int		check_instr(char **instr);
int		set_int_arr(char **argv, int argc, t_app **app);
#endif
