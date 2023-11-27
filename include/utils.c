/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:12:48 by guortun-          #+#    #+#             */
/*   Updated: 2023/11/23 20:15:04 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_stack_a(int size, int *arr, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_stackadd_node(&stack, ft_stacknew(arr[i]));
		i++;
	}
	free(arr);
	return (stack);
}

void	ft_stackadd_node(t_stack **stack, t_stack *new)
{
	if (stack == NULL)
	{
		write(1, "Error [CREATE STACK]", 20);
		exit(1);
	}
	new->next = *stack;
	*stack = new;
}

t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_print_stack_horizontal(t_stack *stack_a, t_stack *stack_b)
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

bool	has_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j] && array[i] != 0)
			{
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}
