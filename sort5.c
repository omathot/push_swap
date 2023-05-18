/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:32:08 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/18 21:47:59 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack *stack, t_stack *stack_b)
{
	move_to_b(stack, stack_b);
	sort_3(stack);
	pa(stack, stack_b);
	pa(stack, stack_b);
}

t_element	*find_min(t_stack *stack)
{
	t_element	*temp;
	t_element	*min_elem;

	temp = stack->head;
	min_elem = stack->head;
	while (temp && temp->pos != -1)
	{
		if (min_elem->index > temp->index)
			min_elem = temp;
		temp = temp->next;
	}
	return (min_elem);
}

void	rotate_to_element(t_stack *stack, t_element *element)
{
	while (stack->head != element)
	{
		if (element->pos < stack->size / 2)
			ra(stack);
		else
			rra(stack);
	}
}

void	move_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	t_element	*min_elem;

	i = 0;
	while (i < 2)
	{
		min_elem = find_min(stack_a);
		rotate_to_element(stack_a, min_elem);
		pb(stack_a, stack_b);
		i++;
	}
}
