/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:17:48 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/20 00:20:58 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_overflow(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	atoi_iterate(str, &res);
	return (sign * res);
}

void	atoi_iterate(const char *str, long *res)
{
	int	i;

	i = 1;
	while (*str && i)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (*res > INT_MAX / 10 || \
				(*res == INT_MAX / 10 && *str - '0' > INT_MAX % 10))
			{
				ft_printf("Error\nInvalid input\n");
				exit(EXIT_FAILURE);
			}
			*res = *res * 10 + *str - '0';
		}
		else
			i = 0;
		str++;
	}
}
