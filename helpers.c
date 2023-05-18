/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:53:18 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/18 20:33:03 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	int			max;
	t_element	*current;

	max = 0;
	current = stack->head;
	while (current)
	{
		if (current->num > max)
			max = current->num;
		current = current->next;
	}
	return (max);
}

int	get_digit(int num, int exp)
{
	return ((num / exp) % 10);
}

int	a_is_sorted(t_stack *stack)
{
	t_element	*temp;

	if (!stack)
		exit_message("error in a is sorted", stack);
	temp = stack->head;
	while (temp->next)
	{
		if (temp->num < temp->next->num)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}

t_element	*get_next_min(t_stack *stack, int current_min)
{
	t_element	*temp;
	t_element	*next_min;

	temp = stack->head;
	next_min = NULL;
	while (temp)
	{
		if (temp->index == -1 && (next_min == NULL || temp->num < next_min->num)
			&& temp->num > current_min)
			next_min = temp;
		temp = temp->next;
	}
	return (next_min);
}
