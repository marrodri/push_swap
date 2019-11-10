/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sortedSt_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:12:05 by marrodri          #+#    #+#             */
/*   Updated: 2019/11/08 15:12:07 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO ADD THE FUNCTIONS TO FINALLY PROPERLY SORT, by rotating and pushing
// elements from stack b to rotating stack a, and finally rotating when everything
// is sorted

void	ft_ToInsrt(t_app **app, t_list **st_a, t_list **st_b)
{
	// 
}

void		ft_rotStBValTop()
{
	// here checks and sets the rotations required in the flags for stack B
}

void		ft_rotStAValTop()
{
	// here checks and sets the rotations required in the flags for stack A
}

void		setSortedInst(t_app **app, t_list **st_a, t_list **st_b)
{
	// IMPORTANT NOTE 
	// if the first element from stack B cannot be inserted 
	// where the first elem of stack A is, find a way to break 
	// 1.- step find the highest val in stack b and the lower value from stack A but still higher than the hi_val of stack B 
	// 2.- check how many ra, rra rb, rrb are needed to rotate the element to the top 
	// 3.- then push 





}