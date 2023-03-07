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



}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_stack	sorted;
	t_stack	temp;

	init_stack_1(&stack_a, &stack_b, (argc - 1));
	if (!init_stack_2(&sorted, &temp, (argc - 1)))
	{
		free(stack_a.ptr);
		free(stack_b.ptr);
		return (ft_printf("Malloc error."));
	}
	init_main_stack(&stack_a, argv, argc);
	make_sorted(&sorted, &stack_a);
	while (stack_a.size > 120)
		partition_chunk(&stack_a, &stack_b, &temp, 60);
	while (stack_a.size > 3)
		partition_half(&stack_a, &stack_b, &temp);
	sort_a(&stack_a);
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
