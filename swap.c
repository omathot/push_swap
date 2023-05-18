/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:38:49 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/17 22:40:34 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_element	*temp;

	if (!stack)
		exit_message("No stack in swap", NULL);
	if(stack->size > 1)
	{
		temp = pop(stack);
		temp->next = stack->head->next;
		stack->head->next = temp;
		stack->size += 1;
		stack->head->pos = 1;
		stack->head->next->pos = 2;
		// adjust_index(stack);
	}
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}