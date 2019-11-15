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
# define SRT_INST {"sa", "ra", "rra", "pb", "sb", "rb", "rrb", "pa"}
// # define PS_STA {"sa", "ra", "rra"}
// # define PS_STB {"sb", "rb", "rrb"}
# define PS_INST_BOTH {"ss", "rr", "rrr"}
# define PS_INS_SZ 11
# define PS_INSB_SZ 5
# define PS_FL_SZ 3
# define SORT_FT_SZ 8
# include "./libft/libft.h"
# include "./libft/ft_printf.h"

typedef	struct	s_flag
{
	int		flag[3];
}				t_flag;

typedef struct	s_app
{

	int		sort_sta_flag[4];
	int		sort_stb_flag[4];
	char	**instr;
	char	**av;
	int		*arr_num;
	int		len_inst;
	int		stIsMerged;
	int		stck_ind;

	int		len_stck; //keep updating this one
	int		stck_a_hi_val;
	int		stck_a_hi_val_ind;
	int		stck_a_low_val;
	int		stck_a_low_val_ind;

	int		len_stck_b; //keep updating this one
	int		stck_b_hi_val;
	int		stck_b_hi_val_ind;
	int		stck_b_low_val_ind;
	int		stck_b_low_val;

	int		hi_stb_val;
	int		low_stb_val;


	int		free_av;
	int		instr_count;
}				t_app;

typedef int		*t_sort(t_list **stack);
typedef int		*t_sort_both(t_list **stack_a, t_list **stack_b);
typedef	int		t_ps_ft(t_list **stack);
typedef	int		t_ps_both_ft(t_list **st_a, t_list **st_b);
int				*swap(t_list **stack);
int				sa(t_list **st_a);
int				ra(t_list **st_a);
int				rra(t_list **st_a);
int				pa(t_list **st_a, t_list **st_b);
int				sb(t_list **st_b);
int				rb(t_list **st_b);
int				rrb(t_list **st_b);
int				pb(t_list **st_a, t_list **st_b);
int				rr(t_list **st_a, t_list **st_b);
int				rrr(t_list **st_a, t_list **st_b);
int				ss(t_list **st_a, t_list **st_b);
void			free_list(t_list **list);
int				*swap_s(t_list **stack_a, t_list **stack_b);
void			push(t_list **stack_a, t_list **stack_b);
int				*rot(t_list **stack);
int				*rot_r(t_list **stack_a, t_list **stack_b);
int				*rrot(t_list **stack);
int				*rrot_r(t_list **stack_a, t_list **stack_b);
int				read_instr(int fd, t_app **app);

int				check_arg(char **argv, int argc, t_app **app);
int				set_int_arr(t_app **app, int i);
int				check_stack(t_list *stack);
int				check_stack_r(t_list *stack);
int				check_stacks(t_list *stack_a, t_list *stack_b);
void			sort_stacks(t_list **stack_a, t_list **stack_b, char *instr);
void			set_stack(t_list **stack, t_app *app);
t_list			*ft_set_node(int num, void *cont, size_t size);
void			add_new_elem(t_list **alist, int num);
int				set_instr(int fd, t_app **app);
int				check_instr(char *instr);
void			free_words(char **instr);
void			free_checker(t_app **app, t_list **st_a, t_list **st_b);


/*
** funtction to set stack A instructions
*/

int				sta_exception(t_list *st_a);
int				ch_ra_sta(t_list *st_a);
int				ch_rra_sta(t_list *st_a);
int				ch_next_low_elem(t_list *stack);

/*
** funtction to set stack B instructions
*/

int				ch_rb_stb(t_list *st_b);
int				ch_rrb_stb(t_list *st_b);
int				ch_next_hi_elem(t_list *stack, t_app *app);

void	set_ft(t_app **app, t_list *st_a, t_list *st_b);

void	setSortedInst(t_app **app, t_list *st_a, t_list *st_b);
void	set_sort_flag(t_app **app, t_list *st_a, t_list *st_b);
void	st_act_ft(t_app **app, t_list **st_a, t_list **st_b);

void	print_stack(t_list **list);

void	mergeStack(t_app **app, t_list **st_a, t_list **st_b);

int		stck_hiVal(t_list *stck);
int		stck_lowVal(t_list *stck);
int		stck_valInd(t_list *stck, int elem);
int		stck_hiValComp(t_list *stck, int limit);





#endif
