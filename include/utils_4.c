/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:44:16 by guortun-          #+#    #+#             */
/*   Updated: 2023/10/03 11:24:30 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	int	i;
	int	j;
	int	num;
	int	siz;

	if (is_sorted(*stack_a) == 1)
		return ;
	siz = size->size_a;
	i = -1;
	while (++i < max_bits(size))
	{
		j = -1;
		while (++j < siz)
		{
			num = (*stack_a)->content;
			if ((num >> i & 1) == 1)
				ra(stack_a, 0);
			else
				pb(stack_a, stack_b, size);
		}
		while (size->size_b != 0)
			pa(stack_a, stack_b, size);
	}
}

int	max_bits(t_size *size)
{
	int	nbr_bits;
	int	max;

	nbr_bits = 0;
	max = size->size_a - 1;
	while ((max >> nbr_bits) != 0)
		nbr_bits++;
	return (nbr_bits);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	write(1, "rrr\n", 4);
}

void	rrb(t_stack **stack_b, int rr)
{
	t_stack	*last;
	t_stack	*prev;

	if ((*stack_b) != NULL && (*stack_b)->next != NULL)
	{
		last = (*stack_b);
		prev = NULL;
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = (*stack_b);
		(*stack_b) = last;
	}
	if (rr == 0)
		write(1, "rra\n", 4);
}

void	rra(t_stack **stack_a, int rr)
{
	t_stack	*last;
	t_stack	*prev;

	if ((*stack_a) != NULL && (*stack_a)->next != NULL)
	{
		last = (*stack_a);
		prev = NULL;
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = (*stack_a);
		(*stack_a) = last;
	}
	if (rr == 0)
		write(1, "rra\n", 4);
}
