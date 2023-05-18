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
	if (size < 1)
		exit(0);
	a->size = 0;
	b->size = 0;
	a->ptr = malloc(sizeof(int) * size);
	if (a->ptr == NULL)
	{
		free(a->ptr);
		error_exit();
		return (0);
	}
	b->ptr = malloc(sizeof(int) * size);
	if (b->ptr == NULL)
	{
		free(a->ptr);
		free(b->ptr);
		error_exit();
		return (0);
	}
	return (1);
}

int	init_stack_2(t_stack *sorted, t_stack *temp, int size)
{
	sorted->size = 0;
	temp->size = 0;
	sorted->ptr = malloc(sizeof(int) * size);
	if (sorted->ptr == NULL)
	{
		free(sorted->ptr);
		error_exit();
		return (0);
	}
	temp->ptr = malloc(sizeof(int) * size);
	if (temp->ptr == NULL)
	{
		free(sorted->ptr);
		free(temp->ptr);
		error_exit();
		return (0);
	}
	return (1);
}

void	init_main_stack(t_stack *a, t_stack *b, char **argv, int argc)
{
	int			i;
	int			x;
	long long	check;

	i = 0;
	x = 1;
	a->size = (argc - 1);
	check_digits(a, b, argv, 1);
	while (i < a->size)
	{
		check = ft_atoll(argv[x]);
		if (!check_int(check))
		{
			free_a_b(a, b);
			error_exit();
		}
		a->ptr[a->size - i - 1] = check;
		i++;
		x++;
	}
	if (check_sort(a) == 1)
	{
		free_a_b(a, b);
		exit(0);
	}
}

void	make_sorted(t_stack *sorted, t_stack *a, t_stack *b, t_stack *temp)
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
			else if (i != x && a->ptr[i] == a->ptr[x])
			{
				free_all(a, b, sorted, temp);
				error_exit();
			}
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
