/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:07:15 by guortun-          #+#    #+#             */
/*   Updated: 2023/10/02 17:43:10 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	int	poped_num;

	poped_num = pop(stack_a);
	size->size_a = size->size_a - 1;
	ft_stackadd_node(stack_b, ft_stacknew(poped_num));
	size->size_b = size->size_b + 1;
	write(1, "pb\n", 3);
}
void	pa(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	int	poped_num;

	poped_num = pop(stack_b);
	size->size_b = size->size_b - 1;
	ft_stackadd_node(stack_a, ft_stacknew(poped_num));
	size->size_a = size->size_a + 1;
	write(1, "pa\n", 3);
}
void	sa(t_stack **stack_a, int ss)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if ((*stack_a) != NULL && (*stack_a)->next != NULL)
	{
		first = (*stack_a);
		second = (*stack_a)->next;
		temp = first->content;
		first->content = second->content;
		second->content = temp;
	}
	if (ss == 0)
		write(1, "sa\n", 3);
}
void	sb(t_stack **stack_b, int ss)
{
	t_stack	*first;
	t_stack	*second;
	int		temp;

	if ((*stack_b) != NULL && (*stack_b)->next != NULL)
	{
		first = (*stack_b);
		second = (*stack_b)->next;
		temp = first->content;
		first->content = second->content;
		second->content = temp;
	}
	if (ss == 0)
		write(1, "sb\n", 3);
}
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	write(1, "ss\n", 3);
}
void	ra(t_stack **stack_a, int rr)
{
	t_stack	*first;
	t_stack	*last;

	if ((*stack_a) != NULL && (*stack_a)->next != NULL)
	{
		first = (*stack_a);
		last = first;
		// Encontrar el último elemento en la pila A
		while (last->next != NULL)
		{
			last = last->next;
		}
		// Mover el primer elemento al final
		last->next = first;
		(*stack_a) = first->next;
		first->next = NULL;
	}
	if (rr == 0)
		write(1, "ra\n", 3);
}
void	rb(t_stack **stack_b, int rr)
{
	t_stack	*first;
	t_stack	*last;

	if ((*stack_b) != NULL && (*stack_b)->next != NULL)
	{
		first = (*stack_b);
		last = first;
		// Encontrar el último elemento en la pila A
		while (last->next != NULL)
		{
			last = last->next;
		}
		// Mover el primer elemento al final
		last->next = first;
		(*stack_b) = first->next;
		first->next = NULL;
	}
	if (rr == 0)
		write(1, "rb\n", 3);
}
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	write(1, "rr\n", 3);
}


