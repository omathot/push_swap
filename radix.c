/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:11:05 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/17 23:07:43 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_idx;
	int	i;
	int	initial_size_a;

	max_idx = get_max_idx(stack_a);
	i = 0;
	while ((max_idx >> i) > 0)
	{
		initial_size_a = stack_a->size;
		while (initial_size_a-- > 0)
		{
			if (((stack_a->head->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		i++;
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
	}
}
