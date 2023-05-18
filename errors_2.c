/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sharsune <sharsune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:48:43 by Sharsune          #+#    #+#             */
/*   Updated: 2023/05/16 22:48:45 by Sharsune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_split_stack(t_stack *a, t_stack *b, char **str)
{
	if (check_sort(a) == 1)
	{
		free_a_b(a, b);
		free_split(str);
		exit(0);
	}
	free_split(str);
}
