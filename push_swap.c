/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:01:34 by sharsune          #+#    #+#             */
/*   Updated: 2023/02/13 17:01:35 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_stack *a, t_stack *b, t_stack *sorted, t_stack *temp)
{
	int	count;
	int	i;

	count = sorted->size - a->size - 1;
	while (count + 1)
	{
		i = sorted->ptr[count];
		if (b->ptr[b->size - 1] == i)
		{
			pa(a, b);
			count--;
		}
		else if (b->ptr[b->size - 2] == i)
			sb_pa_fix(a, b, count--);
		else
		{
			if (move_next(a, b, sorted, count) == 1)
				count--;
			else
				count = count - 2;
		}
	}
	free_all(a, b, sorted, temp);
}

int	move_next(t_stack *a, t_stack *b, t_stack *sorted, int count)
{
	int	next;
	int	next2;
	int	moves;
	int	moves2;

	next = sorted->ptr[count];
	next2 = sorted->ptr[count - 1];
	moves = count_move(b, next);
	moves2 = count_move(b, next2);
	if (moves <= moves2)
	{
		move_nb(b, next);
		pa(a, b);
		return (1);
	}
	else
	{
		move_nb(b, next2);
		pa(a, b);
		move_nb(b, next);
		pa(a, b);
		sa(a);
		return (2);
	}
}

void	move_nb(t_stack *b, int next)
{
	if (b->ptr[b->size - 1] == next)
		return ;
	if (check_rotate(b, next))
	{
		while (b->ptr[b->size - 1] != next)
			rb(b);
	}
	else
	{
		while (b->ptr[b->size - 1] != next)
			rrb(b);
	}
}

int	count_move(t_stack *b, int next)
{
	int	moves;

	moves = next;
	if (b->size - moves < next)
		moves = b->size - next;
	return (moves);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stack	sorted;
	t_stack	temp;
	int		count;

	if (argc == 2)
	{
		count = split_arg(argc, argv, &a, &b);
		init_stack_2(&sorted, &temp, count);
	}
	else
	{
		init_stack_1(&a, &b, (argc - 1));
		init_main_stack(&a, &b, argv, argc);
		init_stack_2(&sorted, &temp, (argc - 1));
	}
	make_sorted(&sorted, &a, &b, &temp);
	while (a.size > 120)
		partition_chunk(&a, &b, &temp, 60);
	while (a.size > 3)
		partition_half(&a, &b, &temp);
	sort_a(&a);
	sort_b(&a, &b, &sorted, &temp);
	return (0);
}
