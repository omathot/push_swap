/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:32:57 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/17 22:47:00 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_r(t_stack *stack)
{
	t_element	*temp;
	int			i;

	i = 1;
	temp = view(stack, stack->size);
	temp->next = stack->head;
	push(stack, temp);
	stack->size -= 1;
	while (i < stack->size + 1)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
	// adjust_index(stack);
}

void	rra(t_stack *stack_a)
{
	reverse_r(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	reverse_r(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}