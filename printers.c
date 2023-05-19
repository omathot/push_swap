/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:27:57 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/19 21:46:24 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_element(t_element	*elem)
{
	printf("num is : %i\n", elem->num);
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
	printf("\n");
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
