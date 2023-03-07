#include "push_swap.h"

int	init_stack_1(t_stack *stack_a, t_stack *stack_b, int size)
{
	stack_a->size = 0;
	stack_b->size = 0;
	stack_a->ptr = malloc(sizeof(int) * size);
	if (!stack_a->ptr)
	{
		free(stack_a->ptr);
		return (0);
	}
	stack_b->ptr = malloc(sizeof(int) * size);
	if (!stack_b->ptr)
	{
		free(stack_a->ptr);
		free(stack_b->ptr);
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

void	init_main_stack(t_stack *stack_a, char **argv, int argc)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	stack_a->size = (argc - 1);
	while (i < stack_a->size)
	{
		stack_a->ptr[stack_a->size - i - 1] = ft_atoi(argv[x]);
		i++;
		x++;
	}
}

void	make_sorted(t_stack *sorted, t_stack *stack_a)
{
	int	i;
	int	x;
	int	count;

	i = 0;
	while (i < stack_a->size)
	{
		x = 0;
		count = 0;
		while (x < stack_a->size)
		{
			if (stack_a->ptr[i] > stack_a->ptr[x])
				count++;
			x++;
		}
		sorted->ptr[count] = stack_a->ptr[i];
		sorted->size++;
		i++;
	}
}

void	make_temp(t_stack *stack_a, t_stack *temp)
{
	int	i;
	int	x;
	int	count;

	i = 0;
	while (i < stack_a->size)
	{
		x = 0;
		count = 0;
		while (x < stack_a->size)
		{
			if (stack_a->ptr[i] > stack_a->ptr[x])
				count++;
			x++;
		}
		temp->ptr[count] = stack_a->ptr[i];
		i++;
	}
}