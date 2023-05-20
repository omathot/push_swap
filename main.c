/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:25:03 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/20 11:03:53 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
	{
		ft_printf("Error original malloc\n");
		exit(EXIT_FAILURE);
	}
	stack_a->head = NULL;
	stack_b->head = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
	if (argc == 1)
		exit(EXIT_FAILURE);
	prep_stacks(stack_a, argc, argv);
	go_sort(stack_a, stack_b, argc);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}

void	dup_check(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (strcmp(argv[i], argv[j]) == 0)
			{
				ft_printf("Error\nDuplicates found\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	num_check(char *argv[])
{
	int		y;
	int		x;

	y = 1;
	while (argv[y])
	{
		x = 0;
		while (argv[y][x])
		{
			if (!(48 <= argv[y][x] && argv[y][x] <= 57) && argv[y][x] != 45)
			{
				ft_printf("Error\nNon numerical characters found\n");
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

void	prep_stacks(t_stack *stack, int argc, char **argv)
{
	t_element	*temp;
	int			i;

	i = 1;
	num_check(argv);
	dup_check(argc, argv);
	while (i < argc)
	{
		temp = (t_element *)malloc(sizeof(t_element));
		if (!temp)
			exit (EXIT_FAILURE);
		temp->num = ft_atoi_overflow(argv[i]);
		temp->index = -1;
		temp->pos = i;
		temp->next = NULL;
		add(stack, temp);
		i++;
	}
	index_numbers(stack);
}

void	hardsorts(int argc, t_stack *stack_a, t_stack *stack_b)
{
	if (argc == 3)
	{
		if (a_is_sorted(stack_a) == 1)
			sa(stack_a);
	}
	if (argc == 4)
		sort_3(stack_a);
	if (argc == 6)
		sort_5(stack_a, stack_b);
}
