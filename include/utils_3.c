/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:46:53 by guortun-          #+#    #+#             */
/*   Updated: 2023/11/27 07:45:36 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_pos(t_stack *stack)
{
	int		smallest;
	int		position;
	int		current_pos;
	t_stack	*current_node;

	if (stack == NULL)
		return (-1);
	smallest = stack->content;
	position = 0;
	current_pos = 0;
	current_node = stack;
	while (current_node != NULL)
	{
		if (current_node->content < smallest)
		{
			smallest = current_node->content;
			position = current_pos;
		}
		current_pos++;
		current_node = current_node->next;
	}
	return (position);
}

int	get_max_pos(t_stack *stack)
{
	int		greatest;
	int		position;
	int		current_pos;
	t_stack	*current_node;

	if (stack == NULL)
		return (-1);
	greatest = stack->content;
	position = 0;
	current_pos = 0;
	current_node = stack;
	while (current_node != NULL)
	{
		if (current_node->content > greatest)
		{
			greatest = current_node->content;
			position = current_pos;
		}
		current_pos++;
		current_node = current_node->next;
	}
	return (position);
}

void	find_cases_5(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	int	min_position;

	min_position = get_min_pos((*stack_a));
	if (min_position == 0)
	{
		pb(stack_a, stack_b, size);
	}
	else if (min_position <= size->size_a / 2)
	{
		while (min_position > 0)
		{
			ra(stack_a, 0);
			min_position--;
		}
	}
	else
	{
		while (min_position < size->size_a)
		{
			rra(stack_a, 0);
			min_position++;
		}
	}
}

void	sort5(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	int	a;

	a = size->size_a;
	if (!is_sorted((*stack_a)))
	{
		while (size->size_b != (a - 3))
		{
			find_cases_5(stack_a, stack_b, size);
		}
		sort3(stack_a, size->size_a);
		while (size->size_b != 0)
			pa(stack_a, stack_b, size);
	}
}

void	moves(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	if (size->size_a <= 3)
		sort3(stack_a, size->size_a);
	else if (size->size_a >= 4 && size->size_a < 10)
		sort5(stack_a, stack_b, size);
	else if (size->size_a >= 10)
		radix(stack_a, stack_b, size);
}
