/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:23:25 by sharsune          #+#    #+#             */
/*   Updated: 2023/02/15 18:23:27 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	a->ptr[a->size] = b->ptr[b->size - 1];
	a->size++;
	b->size--;
}

void	pb(t_stack *a, t_stack *b)
{
	b->ptr[b->size] = a->ptr[a->size];
	b->size++;
	a->size--;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb");
}

void	rotate(t_stack *stack)
{
	int	i;
	int	temp;

	i = 1;
	temp = stack->ptr[stack->size];
	while (i < stack->size)
	{
		stack->ptr[stack->size] = stack->ptr[stack->size - i];
		i++;
	}
	stack->ptr[0] = temp;
}
