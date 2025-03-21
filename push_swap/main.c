/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:43:09 by malbayra          #+#    #+#             */
/*   Updated: 2025/03/11 11:03:43 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arg_counter(char **av)
{
	int	counter;

	counter = 0;
	while (*av++)
		counter++;
	return (counter + 1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	size = ac;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			return (1);
		ac = arg_counter(av);
	}
	else
		av += 1;
	stack_init(&a, av, ac, size == 2);
	if (!stack_sorted(a))
		radix_sort(&a, &b, stack_len(a));
	free_stack(&a);
	if (stack_len(b) != 0)
		free_stack(&b);
	return (0);
}
