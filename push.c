/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:26:08 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/18 14:22:03 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *dest, t_stack *src)
{
	t_element	*temp;
	int			i;

	i = 1;
	if (!src && src->size > 0)
	{
		free_list(src);
		exit_message("Error in push_stack", dest);
	}
	push(dest, pop(src));
	temp = dest->head;
	while (i < dest->size + 1)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
	// adjust_index(dest);
}

void	pa(t_stack *a, t_stack *b)
{
	push_stack(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push_stack(b, a);
	b->head->pos = -1;
	ft_printf("pb\n");
}
