/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:07:20 by guortun-          #+#    #+#             */
/*   Updated: 2023/09/26 18:06:16 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void sort_3_items(t_stack **stack_a, t_stack **stack_b)
{
    int numbers[3];
    int i;
    
    i = 0;
    t_stack *aux = (*stack_a);
    while ((*stack_a)){
        numbers[i] = (*stack_a)->content;
        (*stack_a) = (*stack_a)->next;
        i++;
    }
    (*stack_a) = aux;
    if (numbers[0] == 1 && numbers[1] == 3)
    {
        rra(stack_a, 0);
        sa(stack_a, 0);
    }
}
void	sort3(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		ft_print_stack((*stack_a));
	else
        sort_3_items(stack_a, stack_b);
}

void	moves(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	if (size->size_a <= 3)
	    sort3(stack_a, stack_b);
}
int	pop(t_stack **stack)
{
	if (*stack == NULL)
	{
		printf("La pila está vacía.\n");
		return (-1); // Valor de error
	}
	t_stack *temp = *stack;
	*stack = (*stack)->next;
	int content = temp->content;
	free(temp);
	return (content);
}