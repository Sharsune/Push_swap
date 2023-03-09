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

void	copy_sort(t_stack *a, t_stack *temp)
{
	int	i;

	i = 0;
	temp->size = a->size;
	while (i < a->size)
	{
		temp->ptr[i] = a->ptr[i];
		i++;
	}
	make_temp(a, temp);
}

void	partition_half(t_stack *a, t_stack *b, t_stack *temp)
{
	int	count;
	int	median;
	int	median_b;

	copy_sort(a, temp);
	median = temp->size / 2;
	median_b = median / 2;
	count = median;
	while (count)
	{
		if (a->ptr[a->size - 1] < temp->ptr[median])
		{
			pb(a, b);
			if (b->ptr[b->size - 1] < temp->ptr[median_b])
				rb(b);
		}
		else
			ra(a);
		count--;
	}
}

void	partition_chunk(t_stack *a, t_stack *b, t_stack *temp, int size)
{
	int	median;
	int	median_b;

	copy_sort(a, temp);
	median = temp->ptr[size];
	median_b = temp->ptr[size / 2];
	while (size)
	{
		if (a->ptr[a->size - 1] < temp->ptr[median])
		{
			pb(a, b);
			if (b->ptr[b->size - 1] < temp->ptr[median_b])
				rb(b);
		}
		else
			ra(a);
		size--;
	}
}

int	check_rotate(t_stack *b, int next, int moves)
{
	if (b->size - next <= moves)
		return (0);
	return (1);
}
