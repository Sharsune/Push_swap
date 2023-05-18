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

int			split_arg(int argc, char **argv, t_stack *a, t_stack *b);
void		error_exit(void);
void		init_main_stack(t_stack *a, t_stack *b, char **argv, int argc);
int			init_stack_1(t_stack *a, t_stack *b, int size);
int			init_stack_2(t_stack *sorted, t_stack *temp, int size);
void		init_split_stack(t_stack *a, t_stack *b, char **str);
void		swap(t_stack *stack);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		rotate(t_stack *stack);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		reverse_rotate(t_stack *stack);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		make_sorted(t_stack *sorted, t_stack *a, t_stack *b, t_stack *temp);
void		make_temp(t_stack *a, t_stack *temp);
void		copy_sort(t_stack *a, t_stack *temp);
void		partition_half(t_stack *a, t_stack *b, t_stack *sorted);
void		partition_chunk(t_stack *a, t_stack *b, t_stack *temp, int size);
void		sort_a(t_stack *a);
void		sort_b(t_stack *a, t_stack *b, t_stack *sorted, t_stack *temp);
int			find_next(t_stack *b, int nb);
int			count_move(t_stack *b, int next);
int			check_rotate(t_stack *b, int next);
int			move_next(t_stack *a, t_stack *b, t_stack *sorted, int count);
void		move_nb(t_stack *b, int next);
void		free_a_b(t_stack *a, t_stack *b);
void		free_all(t_stack *a, t_stack *b, t_stack *sorted, t_stack *temp);
void		sb_pa_fix(t_stack *a, t_stack *b, int count);
long		check_int(long long nbr);
int			check_sort(t_stack *a);
void		free_split(char **str);
void		check_split_stack(t_stack *a, t_stack *b, char **str);
void		check_digits(t_stack *a, t_stack *b, char **argv, int begin);
long long	ft_atoll(char *str);

#endif
