/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:11:22 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/27 18:17:06 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(char c)
{
	return (((c >= 9 && c <= 13) || c == 32));
}

long	ft_atol(char *string)
{
	long	number;
	long	index;
	int		sign;

	index = 0;
	while (ft_iswhitespace(string[index]))
		index++;
	sign = 1;
	if (string[index] == '+' || string[index] == '-')
	{
		if (string[index] == '-')
			sign = -1;
		index++;
	}
	number = 0;
	while (ft_isdigit(string[index]))
	{
		number = number * 10 + (string[index] - '0');
		index++;
		if (number > INT_MAX || number < INT_MIN)
			return (2147483648);
	}
	return (number * sign);
}
