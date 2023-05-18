/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardsorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:57:42 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/18 21:32:39 by oscarmathot      ###   ########.fr       */
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
