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
void	init_main_stack(t_stack *stack_a, char **argv, int argc)
{
	int	i;

	i = 0;
	stack_a->size = argc ;
	while (i <= (argc - 1))
	{
		stack_a->ptr[--stack_a->size] = ft_atoi(argv);
		i++;
	}
}

void	init_stack(t_stack *stack, int size)
{
	stack->size = 0;
	stack->ptr = malloc(sizeof(int) * size);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int	i;

	init_stack(&stack_a, (argc - 1));
	init_stack(&stack_b, (argc - 1));
	init_main_stack(&stack_a, argv, argc);





}