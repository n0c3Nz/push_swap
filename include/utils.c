/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:09:15 by guortun-          #+#    #+#             */
/*   Updated: 2023/09/26 16:11:53 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_stackadd_node(stack_a, ft_stacknew(5));
t_stack	*create_stack_a(int size, int *arr, t_stack *stack) //Crear nuevo stack
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_stackadd_node(&stack, ft_stacknew(arr[i]));
		i++;
	}
	free(arr);
	return (stack);
}
void	ft_stackadd_node(t_stack **stack, t_stack *new) //Añadir nuevo nodo
{
	t_stack *aux;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	aux = *stack;
	while (aux->next)
	{
		aux = aux->next;
	}
	aux->next = new;
}

t_stack	*ft_stacknew(int content) //Añadir número al nodo
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_print_stack(t_stack *stack) //Imprimir todos los elementos del stack
{
	while (stack)
	{
		printf("%d\n", (int)stack->content);
		stack = stack->next;
	}
}
void	ft_print_stack_horizontal(t_stack *stack_a, t_stack *stack_b)
	//Imprimir todos los elementos del stack
{
	printf("\n--------------\n");
	printf("A:");
	while (stack_a)
	{
		printf(" %d |", (int)stack_a->content);
		stack_a = stack_a->next;
	}
	printf("\n");
	printf("B:");
	while (stack_b)
	{
		printf(" %d |", (int)stack_b->content);
		stack_b = stack_b->next;
	}
	printf("\n--------------\n");
}