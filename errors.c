/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:18:18 by sharsune          #+#    #+#             */
/*   Updated: 2023/03/20 16:18:19 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_arg(int argc, char **argv, t_stack *a, t_stack *b)
{
	int		i;
	char	**str;

	i = 0;
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		while (str[i])
			i++;
		check_digits(a, b, str, 0);
		init_stack_1(a, b, i);
		init_split_stack(a, b, str);
		return (i);
	}
	return (0);
}

void	init_split_stack(t_stack *a, t_stack *b, char **str)
{
	int			i;
	int			x;
	int			count;
	long long	check;

	i = 0;
	x = 0;
	count = 0;
	while (str[count] != NULL)
		count++;
	a->size = (count);
	while (i < a->size)
	{
		check = ft_atoll(str[i]);
		if (!check_int(check))
		{
			free_a_b(a, b);
			free_split(str);
			error_exit();
		}
		a->ptr[a->size - i - 1] = ft_atoll(str[i]);
		i++;
		x++;
	}
	check_split_stack(a, b, str);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_all(t_stack *a, t_stack *b, t_stack *sorted, t_stack *temp)
{
	free(a->ptr);
	free(b->ptr);
	free(sorted->ptr);
	free(temp->ptr);
}

void	sb_pa_fix(t_stack *a, t_stack *b, int count)
{
	sb(b);
	pa(a, b);
	count += 0;
}
