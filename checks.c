/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharsune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:32:31 by sharsune          #+#    #+#             */
/*   Updated: 2023/04/17 18:32:32 by sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(char *str)
{
	int			c;
	long long	totalnumber;
	int			negative;

	c = 0;
	totalnumber = 0;
	negative = 1;
	while ((str[c] >= 9 && str[c] <= 13) || (str[c] == 32))
		c++;
	if (str[c] == '-')
		negative = negative * -1;
	if ((str[c] == '-') || (str[c] == '+'))
		c++;
	if (str[c] == 0 && str[c + 1] == 0)
		return (0);
	while ((str[c] != '\0') && (str[c] >= '0' && str[c] <= '9'))
	{
		totalnumber = totalnumber * 10 + str[c] - '0';
		if (totalnumber < 0)
		{
			return (2147483649);
		}
		c++;
	}
	return (totalnumber = totalnumber * negative);
}

long	check_int(long long nbr)
{
	if (nbr > 2147483647)
		return (0);
	if (nbr < -2147483648)
		return (0);
	return (1);
}

void	free_a_b(t_stack *a, t_stack *b)
{
	free(a->ptr);
	free(b->ptr);
}

int	check_sort(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->ptr[i] == a->ptr[i + 1])
			return (0);
		if (a->ptr[i] < a->ptr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
