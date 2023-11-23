/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:23:30 by guortun-          #+#    #+#             */
/*   Updated: 2023/11/23 12:12:16 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *arrayzer(int size, char **argv)
{
	int *array;
	int i = 0;
	int j = 0;

	array = (int *)malloc(size * sizeof(int));
	while (j < size)
	{
		array[j] = ft_atoi(argv[i + 1]);
		j++;
		i++;
	}
	return array;
}

int	is_empty(t_stack *stack)
{
	return (stack == NULL);
}

int	peek(t_stack *stack)
{
	if (!is_empty(stack))
	{
		return (stack->content);
	}
	else
	{
		write(2, "The stack is empty, no peek is possible.\n", 42);
		exit(EXIT_FAILURE);
	}
}

int	str_int_limits(char *str)
{
	int	pos;
	int	limit;
	int	length;

	pos = 0;
	limit = 0;
	while (ft_isspace(str[pos]))
		++pos;
	if (str[pos] == '+')
		++pos;
	else if (str[pos] == '-')
		limit = ++pos;
	while (str[pos] == '0')
		++pos;
	length = ft_strlen(&str[pos]);
	if (length == 10)
	{
		if ((limit && ft_strncmp(&str[pos], "2147483648", length) > 0)
			|| (!limit && ft_strncmp(&str[pos], "2147483647", length) > 0))
			return (1);
	}
	else if (length > 10)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_size	size;
	int		*array;

	if (!are_all_numbers(argv, argc))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	stack_b = NULL;
	stack_a = NULL;
	size.size_a = argc - 1;
	size.size_b = 0;
	if (checker(argv))
		return (1);
	array = arrayzer(argc - 1, argv);
	for (int i = 0; i < argc - 1; i++)
		printf("%d\n", array[i]);
	if (has_duplicates(array, argc) == true)
		exit(1);
	stack_a = create_stack_a(size.size_a, array, stack_a);
	moves(&stack_a, &stack_b, &size);
	return (0);
}
