/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:29:17 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/27 18:01:37 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	create_list(t_stack **a, long *numbers, int argc)
{
	int	index;

	index = 0;
	while (index < argc - 1)
	{
		if (append_node(a, numbers[index]))
			return (1);
		index++;
	}
	free(numbers);
	return (0);
}

static int	error_overflow(long *nbr, int index, char **argv)
{
	*nbr = ft_atol(argv[index]);
	if (*nbr > INT_MAX)
	{
		write(2, OVERFLOW, ft_strlen(OVERFLOW));
		return (1);
	}
	return (0);
}

void	stack_init(t_stack **a, char **argv, int argc, int flag_argc_2)
{
	long	nbr;
	int		index;
	long	*numbers;

	index = 0;
	numbers = malloc(sizeof(long) * (argc - 1));
	if (numbers == NULL)
		error_free(a, argv, flag_argc_2, NULL);
	while (argv[index])
	{
		if (error_syntax(argv[index]))
			error_free(a, argv, flag_argc_2, numbers);
		if (error_overflow(&nbr, index, argv))
			error_free(a, argv, flag_argc_2, numbers);
		numbers[index++] = (int)nbr;
	}
	if (error_repetition(numbers, argc - 1))
		error_free(a, argv, flag_argc_2, numbers);
	numbers = normalize(numbers, argc - 1);
	if (numbers == NULL)
		error_free(a, argv, flag_argc_2, NULL);
	if (create_list(a, numbers, argc))
		error_free(a, argv, flag_argc_2, numbers);
	if (flag_argc_2)
		free_matrix(argv);
}


void	user_message(char *string)
{
	if (!ft_strncmp(string, "pa", 2))
		write(1, PA, ft_strlen(PA));
	else if (!ft_strncmp(string, "pb", 2))
		write(1, PB, ft_strlen(PB));
	else if (!ft_strncmp(string, "rra", 3))
		write(1, RRA, ft_strlen(RRA));
	else if (!ft_strncmp(string, "rrb", 3))
		write(1, RRB, ft_strlen(RRB));
	else if (!ft_strncmp(string, "rrr", 3))
		write(1, RRR, ft_strlen(RRR));
	else if (!ft_strncmp(string, "ra", 2))
		write(1, RA, ft_strlen(RA));
	else if (!ft_strncmp(string, "rb", 2))
		write(1, RB, ft_strlen(RB));
	else if (!ft_strncmp(string, "rr", 2))
		write(1, RR, ft_strlen(RR));
	else if (!ft_strncmp(string, "sa", 2))
		write(1, SA, ft_strlen(SA));
	else if (!ft_strncmp(string, "sb", 2))
		write(1, SB, ft_strlen(SB));
	else if (!ft_strncmp(string, "ss", 2))
		write(1, SS, ft_strlen(SS));
}
