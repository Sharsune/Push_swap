/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:34:05 by sharsune          #+#    #+#             */
/*   Updated: 2023/03/07 13:34:07 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_1(t_stack *a, t_stack *b, int size)
{
	a->size = 0;
	b->size = 0;
	a->ptr = malloc(sizeof(int) * size);
	if (!a->ptr)
	{
		free(a->ptr);
		return (0);
	}
	b->ptr = malloc(sizeof(int) * size);
	if (!b->ptr)
	{
		free(a->ptr);
		free(b->ptr);
		return (0);
	}
	return (1);
}

int	init_stack_2(t_stack *sorted, t_stack *temp, int size)
{
	sorted->size = 0;
	temp->size = 0;
	sorted->ptr = malloc(sizeof(int) * size);
	if (!sorted->ptr)
	{
		free(sorted->ptr);
		return (0);
	}
	temp->ptr = malloc(sizeof(int) * size);
	if (!temp->ptr)
	{
		free(sorted->ptr);
		free(temp->ptr);
		return (0);
	}
	return (1);
}

void	init_main_stack(t_stack *a, char **argv, int argc)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	a->size = (argc - 1);
	while (i < a->size)
	{
		a->ptr[a->size - i - 1] = ft_atoi(argv[x]);
		i++;
		x++;
	}
}

void	make_sorted(t_stack *sorted, t_stack *a)
{
	int	i;
	int	x;
	int	count;

	i = 0;
	while (i < a->size)
	{
		x = 0;
		count = 0;
		while (x < a->size)
		{
			if (a->ptr[i] > a->ptr[x])
				count++;
			x++;
		}
		sorted->ptr[count] = a->ptr[i];
		sorted->size++;
		i++;
	}
}

void	make_temp(t_stack *a, t_stack *temp)
{
	int	i;
	int	x;
	int	count;

	i = 0;
	while (i < a->size)
	{
		x = 0;
		count = 0;
		while (x < a->size)
		{
			if (a->ptr[i] > a->ptr[x])
				count++;
			x++;
		}
		temp->ptr[count] = a->ptr[i];
		i++;
	}
}
