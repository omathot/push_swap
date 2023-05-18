/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 01:01:01 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/18 20:25:10 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long long	n;
	int			i;
	int			multi;

	if (!str)
		exit (EXIT_FAILURE);
	i = 0;
	n = 0;
	multi = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		multi *= -1;
		i += 1;
	}
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * multi);
}

void	limit_check(t_stack *stack)
{
	t_element	*temp;

	temp = stack->head;
	while (temp->next)
	{
		if (temp->num > 2147483647)
		{
			ft_printf("Error\ninput higher than int max found\n");
			exit(EXIT_FAILURE);
		}
		temp = temp->next;
	}
}
