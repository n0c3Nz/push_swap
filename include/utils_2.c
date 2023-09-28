/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:07:20 by guortun-          #+#    #+#             */
/*   Updated: 2023/09/28 20:15:06 by guortun-         ###   ########.fr       */
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
int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int findMin(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int *extract_numbers(t_stack **stack_a)
{
    int i;

	i = 0;
    t_stack *aux;
	aux = (*stack_a);

    int *numbers = (int *)malloc(3 * sizeof(int)); // Aloca memoria para los números

    if (numbers == NULL) {
        // Manejo de error en caso de fallo en la asignación de memoria
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }

    while ((*stack_a) && i < 3) {
        numbers[i] = (*stack_a)->content;
        (*stack_a) = (*stack_a)->next;
        i++;
    }

    (*stack_a) = aux;
    
    return numbers;
}
void find_cases(int numbers[], int min, int max, t_stack **stack_a)
{
	if (numbers[0] == min && numbers[1] == max)
    {
        rra(stack_a, 0);
        sa(stack_a, 0);
    }
	else if (numbers[1] == min && numbers[2] == max)//213
		sa(stack_a, 0);
	else if (numbers[1] == max && numbers[2] == min)//231
		rra(stack_a, 0);
	else if (numbers[0] == max && numbers[1] == min)//312
		ra(stack_a, 0);
	else if (numbers[0] == max && numbers[2] == min)//321
	{
        rra(stack_a, 0);
        rra(stack_a, 0);
        sa(stack_a, 0);
	}
}
void sort_3_items(t_stack **stack_a, int size)
{
	int *numbers;
	int max;
	int min;
	if (size < 3)
	{
		ra(stack_a, 0);
		return;
	}
	numbers = extract_numbers(stack_a);
	max = findMax(numbers, 3);
	min = findMin(numbers, 3);
    find_cases(numbers, min, max, stack_a);	
	free(numbers);
}
void	sort3(t_stack **stack_a, int size)
{
	if (!(is_sorted(*stack_a)))
		sort_3_items(stack_a, size);
}
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
void sort5(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	int min_position;
	int	n_of_moves;
	while (size->size_b != 2)
	{
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
	sort3(stack_a, size->size_a);
	pa(stack_a, stack_b, size);
	pa(stack_a, stack_b, size);
}
void	moves(t_stack **stack_a, t_stack **stack_b, t_size *size)
{
	if (size->size_a <= 3)
	    sort3(stack_a, size->size_a);
	else if(size->size_a == 5)
		sort5(stack_a, stack_b, size);
	if ((*stack_b) == NULL)
		printf("");
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