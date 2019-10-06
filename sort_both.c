

#include "push_swap.h"

int		rr(t_list **st_a, t_list **st_b)
{
	int *i;

	i = rot_r(st_a, st_b);
	ft_printf("rr\n");
	return (*i);
}

int		rrr(t_list **st_a, t_list **st_b)
{
	int *i;

	rrot_r(st_a, st_b);
	ft_printf("rrr\n");
	return (*i);
}

int		ss(t_list **st_a, t_list **st_b)
{
	int *i;

	swap_s(st_a, st_b);
	ft_printf("ss\n");
	return (*i);
}