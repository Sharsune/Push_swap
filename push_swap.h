/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:01:26 by sharsune          #+#    #+#             */
/*   Updated: 2023/02/13 17:01:27 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*ptr;
	int	size;
}	t_stack;

void	init_main_stack(t_stack *stack_a, char **argv, int argc);
int		init_stack_1(t_stack *stack_a, t_stack *stack_b, int size);
int		init_stack_2(t_stack *sorted, t_stack *temp, int size);
void	swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	print_stack(t_stack *stack);
void	make_sorted(t_stack *sorted, t_stack *stack_a);
void	make_temp(t_stack *stack_a, t_stack *temp);
void	copy_sort(t_stack *stack_a, t_stack *temp);
void	partition_half(t_stack *stack_a, t_stack *stack_b, t_stack *sorted);
void	partition_chunk(t_stack *stack_a, t_stack *stack_b, t_stack *temp, int size);
void	sort_a(t_stack *a);

#endif
