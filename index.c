/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:36:10 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/18 20:25:37 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_numbers(t_stack *stack)
{
	int			i;
	int			current_min;
	t_element	*next_min;

	i = 0;
	current_min = INT_MIN;
	next_min = get_next_min(stack, current_min);
	while (next_min != NULL)
	{
		next_min->index = i++;
		current_min = next_min->num;
		next_min = get_next_min(stack, current_min);
	}
}

int	get_max_idx(t_stack *stack)
{
	int			max_index;
	t_element	*temp;

	max_index = 0;
	temp = stack->head;
	while (temp)
	{
		if (temp->index > max_index)
			max_index = temp->index;
		temp = temp->next;
	}
	return (max_index);
}
