/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:22:20 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/18 14:21:12 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push(t_stack *stack, t_element *new_elem)
{
	new_elem->next = stack->head;
	stack->head = new_elem;
	stack->size += 1;
	return(stack->size);
}

void	add(t_stack *stack, t_element *new_elem)
{
	t_element *current;

	if (stack->head == NULL)
	{
		new_elem->next = NULL;
		stack->head = new_elem;
	}
	else
	{
		current = stack->head;
		while (current->next != NULL)
			current = current->next;
		new_elem->next = NULL;
		current->next = new_elem;
	}
	stack->size += 1;
}

t_element	*pop(t_stack *stack)
{
	t_element	*temp;

	temp = stack->head;
	stack->head = stack->head->next;
	stack->size -= 1;
	return (temp);
}

t_element	*view(t_stack *stack, int n)
{
	t_element	*current;
	int			i;

	i = 0;
	if (!stack)
		exit_message("No stack in view", NULL);
	if (n > stack->size)
		exit_message("Asking for element outside of stack", stack);
	current = stack->head;
	while (i < n && current->next)
	{
		if (i > 0)
			current = current->next;
		i++;
	}
	return (current);
}

void	print_element(t_element	*elem)
{
	ft_printf("num is : %i\n", elem->num);
}

void	print_stack(t_stack	*stack)
{
	int		i;
	
	i = 0;
	while (i < stack->size)
	{
		print_element(view(stack, i + 1));
		i++;
	}
	ft_printf("\n");
}

void	print_elem_pos(t_element	*elem)
{
	ft_printf("pos is : %i\n", elem->pos);
}

void	print_pos(t_stack	*stack)
{
	int		i;
	
	i = 0;
	while (i < stack->size)
	{
		print_elem_pos(view(stack, i + 1));
		i++;
	}
	ft_printf("\n");
}