/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:01:06 by malbayra          #+#    #+#             */
/*   Updated: 2025/03/17 02:07:47 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit(int bit_index, int n)
{
	return (n >> bit_index & 1);
}

void	operations(t_stack **a, t_stack **b, int bit_index)
{
	int	size;
	int	index;

	while (*b)
		push(a, b, "pa");
	size = stack_len(*a);
	index = 0;
	while (index < size)
	{
		if ((stack_sorted(*a) && *b == NULL))
			break ;
		if (get_bit(bit_index, (*a)->value))
			rotate(a, NULL, "ra");
		else
			push(b, a, "pb");
		index++;
	}
}

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	index;

	index = -1;
	if (size == 2)
		swap(a, 0, "sa");
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_five(a, b);
	else
	{
		while (1)
		{
			++index;
			operations(a, b, index);
			if ((stack_sorted(*a) && *b == NULL))
				break ;
		}
	}
}
