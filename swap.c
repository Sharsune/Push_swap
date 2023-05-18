/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:03:48 by sharsune          #+#    #+#             */
/*   Updated: 2023/02/13 17:03:51 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->ptr[stack->size - 1];
	stack->ptr[stack->size - 1] = stack->ptr[stack->size - 2];
	stack->ptr[stack->size - 2] = temp;
}

void	check_digits(t_stack *a, t_stack *b, char **argv, int begin)
{
	int	i;
	int	k;

	k = begin;
	while (argv[k])
	{
		i = 0;
		if (argv[k][i] == '-' || argv[k][i] == '+')
			i++;
		if (!argv[k][i] || !ft_isdigit(argv[k][i]))
		{
			free_a_b(a, b);
			error_exit();
		}
		while (argv[k][i])
		{
			if (!ft_isdigit(argv[k][i]))
			{
				free_a_b(a, b);
				error_exit();
			}
			i++;
		}
		k++;
	}
}
