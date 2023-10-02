/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:44:50 by guortun-          #+#    #+#             */
/*   Updated: 2023/10/02 17:29:25 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int get_min_pos(t_stack *stack)
{
    if (stack == NULL) {
        fprintf(stderr, "La pila está vacía.\n");
        return -1; // Valor sentinela para indicar un error
    }

    int smallest = stack->content;
    int position = 0;
    int currentPos = 0;
    t_stack *currentNode = stack;

    while (currentNode != NULL) {
        if (currentNode->content < smallest) {
            smallest = currentNode->content;
            position = currentPos;
        }
        currentPos++;
        currentNode = currentNode->next;
    }

    return position;
}
int get_max_pos(t_stack *stack)
{
    if (stack == NULL) {
        fprintf(stderr, "La pila está vacía.\n");
        return -1; // Valor sentinela para indicar un error
    }

    int greatest = stack->content;
    int position = 0;
    int currentPos = 0;
    t_stack *currentNode = stack;

    while (currentNode != NULL) {
        if (currentNode->content > greatest) {
            greatest = currentNode->content;
            position = currentPos;
        }
        currentPos++;
        currentNode = currentNode->next;
    }

    return position;
}
void find_cases_5(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	int min_position;
	int	n_of_moves;
	
	min_position = get_min_pos((*stack_a));
	n_of_moves = size->size_a - min_position;
	if (min_position == 0)
		pb(stack_a, stack_b, size);
	else if (min_position == size->size_a - 1)
		rra(stack_a, 0);
	else if (n_of_moves >= size->size_a / 2)
	{
		while (n_of_moves > 0)
		{
			rra(stack_a, 0);
			n_of_moves--;
		}
	}
	else if (n_of_moves < size->size_a / 2)
	{
		while (n_of_moves > 0)
		{
			ra(stack_a, 0);
			n_of_moves--;
		}
	}
}
void sort5(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	if (!is_sorted((*stack_a)))
	{
		while (size->size_b != 2){
			find_cases_5(stack_a, stack_b, size);
			//printf("tamaño B [%d]\n", (*stack_b)->size);
		}
		sort3(stack_a, size->size_a);
		pa(stack_a, stack_b, size);
		pa(stack_a, stack_b, size);
		//ft_print_stack_horizontal((*stack_a), (*stack_b));
	}
}
void	moves(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	if (size->size_a <= 3)
	    sort3(stack_a, size->size_a);
	else if(size->size_a == 5)
		sort5(stack_a, stack_b, size);
	else if (size->size_a >= 10)
		radix(stack_a, stack_b, size);
}
