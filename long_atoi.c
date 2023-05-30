/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:17:48 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/30 20:16:17 by oscarmathot      ###   ########.fr       */
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
	atoi_iterate(str, &res, sign);
	return (sign * res);
}

void	atoi_iterate(const char *str, long *res, int sign)
{
	int	i;

	i = 1;
	while (*str && i)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (sign > 0 && (*res > INT_MAX / 10 || \
				(*res == INT_MAX / 10 && *str - '0' > INT_MAX % 10)))
			{
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			if (sign < 0 && (-*res < INT_MIN / 10 || \
				(-*res == INT_MIN / 10 && - *str + '0' < INT_MIN % 10)))
			{
				ft_printf("Error\n");
				exit(EXIT_FAILURE);
			}
			*res = *res * 10 + *str - '0';
		}
		else
			i = 0;
		str++;
	}
}
