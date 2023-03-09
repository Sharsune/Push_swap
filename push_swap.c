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

void	sort_b(t_stack *a, t_stack *b, t_stack *sorted)
{
	int	count;
	int	i;

	count = sorted->size - a->size - 1;
	while (count + 1)
	{
		ft_printf("number is:%d\n", sorted->ptr[count]);
		print_stack(b);
		i = find_next(b, sorted->ptr[count]);
		if (b->ptr[b->size - 1] == b->ptr[b->size - i - 1])
		{
			pa(a, b);
			count--;
		}
		else if (b->ptr[b->size - 2] == b->ptr[b->size - i - 1])
			sb(b);
		else
		{
			move_nb(b, sorted, i, count);
			pa(a, b);
			count--;
		}
	}
}
if
	move_nb(next)
else
	mov_nb(next2)
	move_nb(next)
	sa;
void	move_nb(t_stack *b, t_stack *sorted, int next, int count)
{
	int	next2;
	int	moves;
	int	moves2;

	next2 = find_next(b, sorted->ptr[count - 1]);
	moves = count_move(b, next);
	moves2 = count_move(b, next2);
	if (moves < moves2)
	{
		while (moves > 0)
		{
			if (check_rotate(b, next, moves))
			{
				rb(b);
			}
			else
				rrb(b);
			moves--;
		}
	}
	else
	{
		while (moves2 > 0)
		{
			if (check_rotate(b, next2, moves2))
			{
				rb(b);
			}
			else
				rrb(b);
			moves2--;
		}
	}
}

int	count_move(t_stack *b, int next)
{
	int	moves;

	moves = next;
	if (b->size - moves < next)
		moves = b->size - next;
	ft_printf("moves:%d\n", moves);
	return (moves);
}

int	find_next(t_stack *b, int nb)
{
	int	i;

	i = 0;
	while (b->ptr[b->size - i - 1] != nb && i < b->size)
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_stack	sorted;
	t_stack	temp;

	init_stack_1(&a, &b, (argc - 1));
	if (!init_stack_2(&sorted, &temp, (argc - 1)))
	{
		free(a.ptr);
		free(b.ptr);
		return (ft_printf("Malloc error."));
	}
	init_main_stack(&a, argv, argc);
	make_sorted(&sorted, &a);
	while (a.size > 120)
		partition_chunk(&a, &b, &temp, 60);
	while (a.size > 3)
		partition_half(&a, &b, &temp);
	sort_a(&a);
	//print_stack(&a);
	//print_stack(&b);
	sort_b(&a, &b, &sorted);
	//print_stack(&a);
	return (0);
}

//remember to delete this function
void	print_stack(t_stack *stack)
{
	int	size;

	size = stack->size - 1;
	ft_printf("stack :\n");
	while (size >= 0)
	{
		ft_printf("%d\n", stack->ptr[size]);
		size--;
	}
}
