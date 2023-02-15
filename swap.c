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

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss");
}

void	swap(t_stack *stack)
{
	int temp;

	temp = stack->ptr[stack->size];
	stack->ptr[stack->size] = stack->ptr[stack->size - 1];
	stack->ptr[stack->size - 1] = temp; 
}
