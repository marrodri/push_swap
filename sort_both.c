

#include "push_swap.h"

int		rr(t_list **st_a, t_list **st_b)
{
	rot_r(st_a, st_b);
	ft_printf("rr\n");
}

int		rrr(t_list **st_a, t_list **st_b)
{
	rrot_r(st_a, st_b);
	ft_printf("rrr\n");
}

int		ss(t_list **st_a, t_list **st_b)
{
	swap_s(st_a, st_b);
	ft_printf("ss\n");
}