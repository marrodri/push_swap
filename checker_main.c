/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:31:29 by marrodri          #+#    #+#             */
/*   Updated: 2019/09/19 16:31:31 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check the av if they are all digit, if any other character founded return 0;
int		check_arg_digit(char **av)
{
	int i;
	int j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if(!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//compare between 2 avs, if both avs are same return 1;
int		ft_argvdup(char **av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (i != j && !ft_strcmp(av[i], av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		int_limit(char *str)
{
	long int l_int;

	// l_int = ft_ato(str, 10);
	if(l_int >= -2147483648 && l_int <= 2147483647)
		return 1;

	return 0;
}

int		set_stck(char **argv, int argc, t_app **app)
{
	int	i;
	int j;
	int	*stck;

	i = 1;
	j = 0;
	if (argv[i][0] == '-')
	{
		//TODO set a flag checker 
		if (!ft_isdigit(argv[i][1]))
		{
			ft_printf("flag founded, checking flag\n");
			i++;
		}
		else
			return 0;
	}
	(*app)->len = argc - i;
	stck = (int*)malloc((*app)->len * sizeof(int));
	// return 1 if there isn't any duplicate or 
	// a different character than a number, or goes the limit of int
	if (check_arg_digit(&argv[i]) && !ft_argvdup(&argv[i]))
	{
		ft_printf("all input are passed, setting stack a with flag\n");
		while(argv[i])
		{
			//here when setting check if a num goes beyond int limit, if does return 0;
			stck[j] = ft_atoi(argv[i]);
			i++;
			j++;
		}
		(*app)->stck = stck;
		return (1);
	}
	return (0);
}

int		set_instr(int fd, t_app **app)
{
	//reads from the stdin the instruction set and the args
	// each instruction is separated by a new line
	//it will read sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
	// return  0 if unrecognized instruction from stdin, enters the process
	//or badly formatted
	return (1);
}

int main(int argc, char **argv)
{
	t_list	*st_a;
	t_list	*st_b;
	t_app	*app;

	st_a = NULL;
	st_b = NULL;
	app = malloc(sizeof(t_app));
	if(argc >= 2)
	{
		//sets the stack a from args readed and sets the instrs from stdin
		if(set_stck(argv, argc, &app) && set_instr(0, &app))
		{
			ft_printf("stack and instructions set ready,\n");
			for(int i = 0; i < app->len; i++)
			{
				ft_printf("stack[%d] is |%d|\n", i, app->stck[i]);
			}
			//sorts the stack a, based from the instructions list,
			//it will be iterated until the list reach to the end point 
			//checks stack_a if its sorted and stack b if its empty
				//if true print OK
			// else print KO
		}
		else
		{
			ft_printf("Error\n");
			// the proccess, displays ERROR and close the program
		}
	}
	else
	{
		ft_printf("usage: stdin instruction | ./checker <argument integer>\n");
	}

	return (0);
}
