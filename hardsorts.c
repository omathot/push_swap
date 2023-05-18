/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardsorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:57:42 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/18 14:19:11 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	int	one;
	int	two;
	int	three;

	one = stack->head->index;
	two = stack->head->next->index;
	three = stack->head->next->next->index;
	if (one < two && one < three && two > three)
	{
		rra(stack);
		sa(stack);
	}
	else if (one > two && two > three)
	{
		sa(stack);
		rra(stack);
	}
	else if (one > two && two < three && one > three)
		ra(stack);
	else if (one > two && two < three && three > one)
		sa(stack);
	else if (one < two && two > three && one > three)
		rra(stack);
}

void	sort_5(t_stack *stack, t_stack *stack_b)
{
	t_element	*temp;
	t_element	*min_elem;
	int			min_index;
	int			i;

	i = 0;
	while (i < 2)
	{
		temp = stack->head;
		min_index = stack->head->index;
		min_elem = stack->head;
		while (temp && temp->pos != -1)
		{
			if (min_index > temp->index)
			{
				min_index = temp->index;
				min_elem = temp;
			}
			temp = temp->next;
		}
		while (stack->head->index != min_index)
		{
			if (min_elem->pos < stack->size / 2)
				ra(stack);
			else
				rra(stack);
		}
		pb(stack, stack_b);
		i++;
	}
	// print_stack(stack);
	sort_3(stack);
	pa(stack, stack_b);
	pa(stack, stack_b);
}
