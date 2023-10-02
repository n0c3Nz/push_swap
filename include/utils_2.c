/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:07:20 by guortun-          #+#    #+#             */
/*   Updated: 2023/10/02 17:41:56 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
		{
			return (0); // El stack no está ordenado
		}
		stack = stack->next;
	}
	return (1); // El stack está ordenado
}
void find_cases_3(int min, int max, t_stack **stack_a)
{
	if (min == 0 && max == 1)
    {
        rra(stack_a, 0);
        sa(stack_a, 0);
    }
	else if (min == 1 && max == 2)//213
		sa(stack_a, 0);
	else if (max == 1 && min == 2)//231
		rra(stack_a, 0);
	else if (max == 0 && min == 1)//312
		ra(stack_a, 0);
	else if (max == 0 && min == 2)//321
	{
        rra(stack_a, 0);
        rra(stack_a, 0);
        sa(stack_a, 0);
	}
}
void sort3(t_stack **stack_a, int size)
{
	if (!(is_sorted(*stack_a)))
	{
		int max;
		int min;
		if (size < 3)
		{
			ra(stack_a, 0);
			return;
		}
		//numbers = extract_numbers(stack_a);
		max = get_max_pos((*stack_a));
		min = get_min_pos((*stack_a));
		find_cases_3(min, max, stack_a);
	}	
}
int pop(t_stack **stack) {
    if (*stack == NULL) {
        printf("La pila está vacía.\n");
        return -1; // Valor de error
    }
    t_stack* temp = *stack;
    *stack = (*stack)->next;
    int data = temp->content;
    free(temp);
    return data;
}