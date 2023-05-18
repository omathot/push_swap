/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 00:24:36 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/17 22:51:30 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_element	*temp;
	t_element	*start;
	int			i;

	i = 1;
	temp = pop(stack);
	view(stack, stack->size)->next = temp;
	temp->next = NULL;
	stack->size += 1;
	start = stack->head;
	while (i < stack->size + 1)
	{
		start->pos = i;
		start = start->next;
		i++;
	}
	// stack->head->pos = 1;
	// view(stack, stack->size)->pos = stack->size;
	// adjust_index(stack);
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}