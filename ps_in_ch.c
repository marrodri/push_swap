
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

// !!!!!! MODIFY FOR CHECKING AN INT BEYOND

// int		int_limit(char *str)
// {
// 	long int l_int;

// 	// l_int = ft_ato(str, 10);
// 	if(l_int >= -2147483648 && l_int <= 2147483647)
// 		return 1;
// 	return 0;
// }



int		check_instr(char **instr)
{
	const char *ps_inst[PS_INS_SZ] = PS_INST;
	int i;
	int j;

	j = 0;
	i = 0;
	while (instr[i])
	{
		j = 0;
		while (1)
		{
			if(j == PS_INS_SZ)
				return (0);
			if(!ft_strcmp(instr[i], ps_inst[j]))
				break;
			j++;
		}
		i++;
	}
	return (1);
}

int		set_instr(int fd, t_app **app)
{
	char *line;
	char *str;
	char *tmp;

	str = ft_strnew(1);
	(*app)->len_inst = 0;
	while (get_next_line(fd, &line))
	{
		ft_printf("line is |%s|\n", line);
		// tmp = buff;
		str = ft_strjoin(str, line);
		free(line); //added
		tmp = str; //added
		str = ft_strjoin(str, "\n");
		free(tmp); //added
		(*app)->len_inst++;
	}
	(*app)->instr = ft_strsplit(str, '\n');
	if(check_instr((*app)->instr))
		return (1);
	return (0);
}

int		set_int_arr(char **argv, int argc, t_app **app)
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
	(*app)->len_stck = argc - i;
	stck = (int*)malloc((*app)->len_stck * sizeof(int));
	// return 1 if there isn't any duplicate or 
	// a different character than a number, or goes the limit of int
	if (check_arg_digit(&argv[i]) && !ft_argvdup(&argv[i]))
	{
		ft_printf("all input are passed, setting stack\n");
		while(argv[i])
		{
			//here when setting check if a num goes beyond int limit, if does return 0;
			stck[j] = ft_atoi(argv[i]);
			i++;
			j++;
		}
		(*app)->arr_num = stck;
		return (1);
	}
	return (0);
}