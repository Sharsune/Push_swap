/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:31:05 by sharsune          #+#    #+#             */
/*   Updated: 2023/02/16 17:31:07 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stack *a)
{
	if (a->size == 2)
	{
		if (a->ptr[a->size - 1] > a->ptr[a->size - 2])
			sa(a);
		return ;
	}
	if (a->ptr[a->size - 1] > a->ptr[a->size - 2]
	&& a->ptr[a->size - 1] > a->ptr[a->size - 3])
		ra(a);
	else if (a->ptr[a->size - 2] > a->ptr[a->size - 3])
		rra(a);
	if (a->ptr[a->size - 1] > a->ptr[a->size - 2])
		sa(a);
}

void	copy_sort(t_stack *stack_a, t_stack *temp)
{
	int	i;

	i = 0;
	temp->size = stack_a->size;
	while (i < stack_a->size)
	{
		temp->ptr[i] = stack_a->ptr[i];
		i++;
	}
	make_temp(stack_a, temp);
}

void	partition_half(t_stack *stack_a, t_stack *stack_b, t_stack *temp)
{
	int	count;
	int	median;
	int median_b;

	copy_sort(stack_a, temp);
	median = temp->size / 2;
	median_b = median / 2;
	count = median;
	while (count)
	{
		if (stack_a->ptr[stack_a->size - 1] < temp->ptr[median])
		{
			pb(stack_a, stack_b);
			if (stack_b->ptr[stack_b->size - 1] < temp->ptr[median_b])
				rb(stack_b);
		}
		else
			ra(stack_a);
		count--;
	}
}

void	partition_chunk(t_stack *stack_a, t_stack *stack_b, t_stack *temp, int size)
{
	int	median;
	int	median_b;
	copy_sort(stack_a, temp);
	median = temp->ptr[size];
	median_b = temp->ptr[size / 2];
	while (size)
	{
		if (stack_a->ptr[stack_a->size - 1] < temp->ptr[median])
		{
			pb(stack_a, stack_b);
			if (stack_b->ptr[stack_b->size - 1] < temp->ptr[median_b])
				rb(stack_b);
		}
		else
			ra(stack_a);
		size--;
	}
}
