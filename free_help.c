/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:36:59 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/17 15:08:06 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *stack)
{
	t_element	*current;
	t_element	*next;

	current = stack->head;
	while (stack->size > 0)
	{
		next = current->next;
		free(current);
		current = next;
		stack->size -= 1;
	}
	stack->head = NULL;
	free(stack);
}

void	exit_message(char *msg, t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	free_list(stack);
	exit(EXIT_FAILURE);
}