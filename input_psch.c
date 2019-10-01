
#include "push_swap.h"

/*
** check the av if they are all digit,
** if any other character founded return 0;
*/

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

// !!!!!! MODIFY FOR CHECKING AN INT BEYOND

// int		int_limit(char *str)
// {
// 	long int l_int;

// 	// l_int = ft_ato(str, 10);
// 	if(l_int >= -2147483648 && l_int <= 2147483647)
// 		return 1;
// 	return 0;
// }

int		check_instr(char *instr)
{
	const char *ps_inst[PS_INS_SZ] = PS_INST;
	int i;

	i = 0;

	while (i < PS_INS_SZ)
	{
		if(!ft_strcmp(instr, ps_inst[i]))
			return 1;
		i++;
	}
	return (0);
}

int		set_instr(int fd, t_app **app)
{
	char *line;
	char *str;
	char *tmp;
	char *tmp_l;

	str = ft_strnew(1);
	(*app)->len_inst = 0;
	ft_printf("here in set_instr!\n");
	while (get_next_line(fd, &line))
	{
		// if ((*app)->instr)
		// 	free(tmp_l);
		if(!check_instr(line))
			return 0;
		tmp = str;
		str = ft_strjoin(str, line);
		// free(tmp);
		tmp = str;
		str = ft_strjoin(str, "\n");
		// free(tmp);
		(*app)->len_inst++;
		tmp_l = line;
	}
	(*app)->instr = ft_strsplit(str, '\n');
	free(str);
	// free(tmp_l);
	ft_printf("instruction set!\n");
	return (1);
}

int		set_int_arr(t_app **app, int i)
{
	int j;
	int *stck;

	j = 0;
	stck = (int*)malloc((*app)->len_stck * sizeof(int));
	if (check_arg_digit(&(*app)->av[i]) && !ft_check_wrd_dup(&(*app)->av[i]))
	{
		while ((*app)->av[i])
		{
			stck[j] = ft_atoi((*app)->av[i]);
			i++;
			j++;
		}
		(*app)->arr_num = stck;
		return (1);
	}
	return (0);
}

int		check_arg(char **argv, int argc, t_app **app)
{
	int	i;

	i = 0;
	if(argc == 2)
	{
		(*app)->len_stck = ft_word_count(argv[1], ' ');
		(*app)->av = ft_strsplit(argv[1], ' ');
	}
	else if (argc > 2)
	{
		i = 1;
		(*app)->av = argv;
		(*app)->len_stck = argc - i;
	}
	if(set_int_arr(app, i))
		return (1);
	return (0);
}