/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:22:05 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/27 18:11:45 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_node(t_stack *top)
{
	if (!top)
		return (NULL);
	while (top->next != NULL)
		top = top->next;
	return (top);
}

int	append_node(t_stack **head, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (1);
	node->next = NULL;
	node->value = nbr;
	if (!(*head))
	{
		*head = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*head);
		last_node->next = node;
		node->prev = last_node;
	}
	return (0);
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

int	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
