/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscarmathot <oscarmathot@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:25:20 by oscarmathot       #+#    #+#             */
/*   Updated: 2023/05/30 20:17:44 by oscarmathot      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "lib/libft/libft.h"
# include "lib/printf/ft_printf.h"

typedef struct s_element
{
	int					num;
	int					index;
	int					pos;
	struct s_element	*next;
}	t_element;

typedef struct s_stack
{
	struct s_element	*head;
	int					size;
}	t_stack;

//
//////////////////////////////////
//			Starts				//
//////////////////////////////////
int			main(int argc, char *argv[]);
void		prep_stacks(t_stack *stack_a, int argc, char **argv);
void		hardsorts(int argc, t_stack *stack_a, t_stack *stack_b);
void		go_sort(t_stack *stack_a, t_stack *stack_b, int argc);

//
//////////////////////////////////
//			Commands			//
//////////////////////////////////
void		swap(t_stack *stack);
void		sa(t_stack	*stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
int			push(t_stack *stack, t_element *new_elem);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		rotate(t_stack *stack);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		reverse_r(t_stack *stack);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

//
//////////////////////////////////
//			Controls			//
//////////////////////////////////
t_element	*pop(t_stack *stack);
t_element	*view(t_stack *stack, int n);
void		push_stack(t_stack *dest, t_stack *src);
void		add(t_stack *stack, t_element *new_elem);

//
//////////////////////////////////
//			Sorts				//
//////////////////////////////////
void		index_numbers(t_stack *stack);
void		sort_2(t_stack *stack);
void		sort_3(t_stack *stack);
void		sort_5(t_stack *stack, t_stack *stack_b);
void		radix_sort(t_stack *stack_a, t_stack *stack_b);

//
//////////////////////////////////
//			Helpers				//
//////////////////////////////////
int			get_max(t_stack *stack);
int			get_digit(int num, int exp);
int			a_is_sorted(t_stack *stack);
t_element	*get_next_min(t_stack *stack, int current_min);
int			get_max_idx(t_stack *stack);
void		dup_check(int argc, char *argv[]);
void		num_check(char *argv[]);
void		adjust_index(t_stack *stack);
void		limit_check(t_stack *stack);
long		ft_atol(const char *str);
void		move_to_b(t_stack *stack_a, t_stack *stack_b);
void		adjust_smallest(t_element *temp, t_element **min_elem,
				int *min_index);
t_element	*find_min(t_stack *stack);
void		rotate_to_element(t_stack *stack, t_element *element);
int			ft_atoi_overflow(const char *str);
void		atoi_iterate(const char *str, long *res, int sign);

//
//////////////////////////////////
//			Printers			//
//////////////////////////////////
void		print_stack(t_stack	*stack);
void		print_element(t_element	*elem);
void		print_pos(t_stack *stack);
void		print_elem_pos(t_element *elem);

//
//////////////////////////////////
//			Free-ers			//
//////////////////////////////////
void		free_list(t_stack *stack);
void		exit_message(char *msg, t_stack *stack);

#endif