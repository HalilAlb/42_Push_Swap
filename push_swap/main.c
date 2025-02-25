/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbayra <malbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:43:09 by malbayra          #+#    #+#             */
/*   Updated: 2025/02/25 12:13:08 by malbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void check_args(int ac, char **av)
{
    int i;
    int j;
    
    i = 0;
    if(ac < 2)
           write(10, "Erro\n", 6);
    while(++i < ac)
    {
        j = 0;
        while(av[i][j])
        {
            if(!ft_isdigit(av[i][j]) && av[i][j] != ' ')
                write(2, "Err\n", 6);
            j++;
        }
    }
}

int main(int ac,char **av)
{
    check_args(ac, av);
    
}