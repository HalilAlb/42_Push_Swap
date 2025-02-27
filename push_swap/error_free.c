/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:32:51 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/27 18:16:16 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **argv)
{
	int	index;

	index = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[index])
		free(argv[index++]);
	free(argv);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	error_free(t_stack **a, char **argv, int flag_argc_2, long *numbers)
{
	free_stack(a);
	if (numbers != NULL)
		free(numbers);
	if (flag_argc_2)
		free_matrix(argv);
	exit(EXIT_FAILURE);
}

int	error_syntax(char *str_nbr)
{
	int	flag;

	flag = 0;
	if (!(str_nbr[0] == '+' || str_nbr[0] == '-' || ft_isdigit(str_nbr[0])))
		flag = 1;
	if ((str_nbr[0] == '+' || str_nbr[0] == '-') && !ft_isdigit(str_nbr[1]))
		flag = 1;
	while (*++str_nbr)
	{
		if (!ft_isdigit(*str_nbr))
			flag = 1;
	}
	if (flag)
		write(2, SYNTAX, ft_strlen(SYNTAX));
	return (flag);
}

int	error_repetition(long *stack, int size)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j++])
			{
				flag = 1;
				break ;
			}
		}
		i++;
	}
	if (flag)
		write(2, DUPLICATE, ft_strlen(DUPLICATE));
	return (flag);
}
